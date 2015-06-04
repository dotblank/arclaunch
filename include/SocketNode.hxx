#include "LaunchNode.hxx"
#include <thread>
#include <atomic>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#ifndef SOCKET_NODE_H_
#define SOCKET_NODE_H_

// Mostly behaves like a LaunchNode with a node generated
namespace arclaunch {
class SocketNode : public LaunchNode {
  typedef struct ::addrinfo Addr;
  std::vector<int> fds;
  int maxfd;
private:
  socket_node_t::socket_sequence seq;
  int domain;
  int type;
  int protocol;
  addrinfo* res;
  void prepareAccept(Addr* addr);
  void acceptConnections();
  // the threads used for accepting connections
  std::thread accThread;
  std::atomic<bool> keep;
public:
  SocketNode(NodeContext& ctx, const socket_node_t& elem);
  virtual ~SocketNode();
  virtual void startup();
  // need to choose a port and an interface, domain name, or an address
  virtual void waitFor();
};

}
#endif
