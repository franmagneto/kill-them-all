kill-them-all
=============

Chamada de sistema que desprotege o processo *init* de receber um *kill -9*

Autores:

* Francisco Machado Magalhães Neto
* Juventino Figueiredo de Lacerda Neto

Pastas
------

* **module**: versão em módulo, sem chamada de sistema, que desprotege o *init* durante o carregamento.

* **syscall**: versão em patch para o kernel do Linux, que implementa a chamada de sistema *kta*.
Acompanha um programa em modo usuário que executa a chamada e o *kill* (*root* necessário para dar o *kill*).

Uso
---

* **Módulo:** Vá até a pasta *module* e execute `make`.

Em seguida, instale o módulo com `# insmod kill-them-all.ko`.
Agora já é possível executar `# kill -9 1`.

* **Chamada de sistema:** Baixe o kernel 3.15.7 do site <https://kernel.org> e extraia.

Opcionalmente, renomeie a pasta para onde o kernel foi extraído para *linux-3.15.7-kta*.
Entre na pasta pelo terminal e aplique o patch com o comando `patch -p1 < <caminho para o patch>/kta.patch`.

Compile o kernel e instale (é possível encontrar diversos tutoriais explicando como fazer na internet).

Compile o programa de usuário com `gcc -o user-call user-call.c` e o execute com `./user-call`.

Obs.: Se o programa for executado como usuário normal, ele apenas desprotegerá o processo *init*, e em seguida é possível executar `kill -9 1` como root. Se for executado como root, o próprio programa já executa a chamada *kill* e mata o processo *init*.
