/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _AUTENTICACAO_H_RPCGEN
#define _AUTENTICACAO_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define PROGRAM 10
#define VERSION 9

#if defined(__STDC__) || defined(__cplusplus)
#define troca 1
extern  int * troca_9(void *, CLIENT *);
extern  int * troca_9_svc(void *, struct svc_req *);
extern int program_9_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define troca 1
extern  int * troca_9();
extern  int * troca_9_svc();
extern int program_9_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_AUTENTICACAO_H_RPCGEN */