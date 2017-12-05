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


struct aux {
	quad_t mensageCriptografada;
	quad_t hashMensagem;
	quad_t hashDaMensagemCriptografada;
	quad_t d;
	quad_t n;
};
typedef struct aux aux;

#define PROGRAM 10
#define VERSION 9

#if defined(__STDC__) || defined(__cplusplus)
#define troca 1
extern  aux * troca_9(aux *, CLIENT *);
extern  aux * troca_9_svc(aux *, struct svc_req *);
extern int program_9_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define troca 1
extern  aux * troca_9();
extern  aux * troca_9_svc();
extern int program_9_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_aux (XDR *, aux*);

#else /* K&R C */
extern bool_t xdr_aux ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_AUTENTICACAO_H_RPCGEN */
