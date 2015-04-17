#include "ScriptNode.hxx"
#include "NodeContext.hxx"

namespace arclaunch {
// ScriptNode
ScriptNode::ScriptNode(NodeContext& ctx, script_t* scriptElem, executable_t::arg_sequence& args, executable_t::env_sequence& envs) :
  appended(scriptElem) {
  // Combine the passed in argument list with the contained argument list
  // Combine the passed in environment list with the contained argument list
  interpreter = ctx.execute(&scriptElem->interpreter(), fuseArgSequence(scriptElem->arg(), args), fuseEnvSequence(scriptElem->env(), envs));
}

ScriptNode::~ScriptNode() {}

bool ScriptNode::isRunning() const {
  return interpreter->isRunning();
}

pid_t ScriptNode::getPid() const {
  return interpreter->getPid();
}

void ScriptNode::waitFor() const {
  return interpreter->waitFor();
}

int ScriptNode::stdin_fd() const {
  return interpreter->stdin_fd();
}

int ScriptNode::stdout_fd() const {
  return interpreter->stdout_fd();
}

int ScriptNode::stderr_fd() const {
  return interpreter->stderr_fd();
}

}
