struct aux{
	hyper mensageCriptografada;
	hyper int hashMensagem;
    hyper hashDaMensagemCriptografada;
    hyper d;
    hyper int n;   
};


program PROGRAM{
	version VERSION{		
		aux troca(aux)=1;
	}=9;
}=10;