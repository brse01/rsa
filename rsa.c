#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long   ///abstrai o ll por long long

//x^h % n
ll square_multiply(ll x,ll H,ll n)
{
    long h;
    unsigned ll r;
    int bin[32];
    int i;

    r = x;
    i = 0;
    /* Converte H em Binario */
    while( H > 0 )
    {
        if (H % 2 == 0)
        {
            bin[i] = 0;
        }
        else
        {
            bin[i] = 1;
        }

        H = H/2;
        i++;

    }

    i--; //t-1

    while(i>0)
    {
        r = (r * r) % n;
        if( bin[--i] == 1 )
        {
            r = (r * x) % n;
        }
    }
    return r;
}

//calcula (a * b) % mod
ll mulmod(ll a, ll b, ll mod)

{
    ll x = 0,y = a % mod;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

//Teste de primalidade de Miller-Rabin.

int Miller(ll p,int iteration)
{
    if ((p < 2) || (p != 2 && p % 2==0))return 0;
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    int i;
    for (i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = square_multiply(a, temp, p);

        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)  return 0;
    }
    return 1;
}

//calcula o mdc de dois numeros
long gcd (ll x, ll y)
{

    while (y)
    {
        long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// algoritmo que verifica se um número usando o pequeno teorema de fermat
int theoremFermat (unsigned int n,int k)
{
    int i;

    if (n <= 1 || n == 4)  return 0;
    if (n <= 3) return 1;
    for (i = 0; i < k; i++)
    {
        //Escolha um número aleatório no intervalo [2..n-2]
        int a = 2 + rand()%(n-4);

        // Pequeno teorema de Fermat
        if (square_multiply(a, n-1, n) != 1)
            return 0;
    }
    return 1;
}

//calcula o inverso multiplicativo de a em mod m
//exemplo inverso multiplicativo de 3 mod 8 é igual 3 , pois 3*3 é congruente a 1 mod 8.
long modInverse(ll a,ll int m)
{
    long m0 = m, t, q;
    long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q é quociente
        q = a / m;
        t = m;
        // m é restante agora, processe o mesmo que o algo de Euclides
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    // Faça x1 positivo
    if (x1 < 0)
        x1 += m0;
    return x1;
}

void primosEntreSI(ll int *m,ll *e){
    while (gcd(*m, *e) > 1)
    {
        (*e) = (*e) + 1;
    }            
}

void escolherPrimos(ll *p, ll *q, ll int *n){
    while (1)
    {
        *p = 2+rand()%100; // Números aleatórios no intervalo [2,101].
        *q = 2+rand()%100; // Números aleatórios no intervalo [2,101].
        *n = ((*p) * (*q));
        if (Miller(*p,10) && Miller(*p,10))
        {
            break;
        }
    }    
}

/*
int main()
{
    //(e,n) par de chave pública
    //(d,n) par de chave privada
    ll d, e,p,q;
    ll int n;
    srand((unsigned)time(NULL));
    //seleciona os número p,q primos de forma aleatoria utilizando o algoritmo de Fermat.
        while (1)
        {
            p = 2+rand()%1000; // Números aleatórios no intervalo [2,1001].
            q = 2+rand()%1000; // Números aleatórios no intervalo [2,1001].
            n = p * q;
    //        printf("p : %lld , q : %lld\n",p,q);
            if (theoremFermat(p,50) && theoremFermat(q,50))
            {
                break;
            }
        }
    //seleciona os número p,q primos de forma aleatoria utilizando o algoritmo de Miller-Rabin.

    while (1)
    {
        p = 2+rand()%100; // Números aleatórios no intervalo [2,101].
        q = 2+rand()%100; // Números aleatórios no intervalo [2,101].
        n = p * q;
        if (Miller(p,10) && Miller(q,10))
        {
            break;
        }
    }
    // Computa a função phi(n) = (p - 1) * (q - 1)
    ll int m = (p - 1) * (q - 1);

    // Escolha um inteiro "e" , 1 < "e" < phi(n), tal que, "e" e phi(n) sejam primos
    // entre si.
    printf("m : %lld\n" , m);
    e = 2;
    while (gcd(m, e) > 1)
    {
        e = e + 1;
    }

    // "d" seja inverso multiplicativo de "e"
    d = modInverse(e, m);
    printf("p:%lld\n" , p);
    printf("q:%lld\n" , q);
    printf("n : %lld\n" , n);
    printf("e : %lld\n" , e);
    printf("d: %lld\n", d);
    //x é a mensagem no formato : long long
    ll x = 110;
    char v[]="100";
    long long ff= 100;

    ll hash;
    // CRIA A HASH DA MENSAGEM

    char comando[]="python SHA224.py";  
    system(comando);
    
    //rotina(v);
    
    char url[]="hash.txt";    
    FILE * arq = openFile(2,url);
    while((fscanf(arq,"%lld \n", &hash))!=EOF ){
    }

    closeFile(arq);
	//(e,n) par de chave pública
    //(d,n) par de chave privada    
    //printf("x : %ld\n", x);
    // mensagem cifrada - Encriptação (usamos par de chaves (e,n) )
    // hash, msgCifrada, d ,n
    ll msgcifrada = square_multiply(hash,d, n);
    printf("msgcifrada %lld\n",msgcifrada);      
    // mensagem decifrada - Decriptação (usamos par de chaves (d,n))
    ll msgdecifrada = square_multiply(msgcifrada, d, n);
    printf("msgdecifrada %lld\n",msgdecifrada);      

    // Agora vamos guardar dentro de um arquivo para o script em python
    // rode a função para calcular hash
    arq = openFile(1,url);
    fprintf(arq,"%lld",msgdecifrada);
    closeFile(arq);    
    //APOS ISSO VAMOS RODA A ROTINA DO PYTHON Para calcular o hash
    rotina();    
    // AGORA VAMOS LER 
    char rr[]="hash.txt";
    arq = openFile(2,rr);
    long long comparar;
    while((fscanf(arq,"%lld \n", &comparar))!=EOF ){
    }
	closeFile(arq);    
	printf("\n #################################### \n");
	printf("HASH aṕos passar pela função %lld\n",hash);    
	printf("hash depois de descriptar %lld\n", comparar);        
    //printf("msg decifrada: %ld\n" , msgdecifrada);

    return 0;
}

*/