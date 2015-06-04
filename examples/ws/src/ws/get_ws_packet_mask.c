#include "ws_encode_decode.h"
// required for NULL
#include <stdlib.h>

char* get_ws_packet_mask(struct ws_packet* pack) {
  char* ret;
  if(!packet_is_masked(pack))
    return NULL;
  char size = pack->size & 0x7F;
  if(pack->size == 0xFF) // 127, 64 bit extended payload
    return pack->v.l.mask;
  else if(pack->size == 0xFE) // 126, 16 bit extended payload
    return pack->v.m.mask;
  else // no extended payload
    return pack->v.s_mask;
}
