# ufmg-alg1-tp2
Trabalho prático 2 da disciplina de Algoritmos I, feito no quarto período da graduação em Sistemas de Informação, pela Universidade Federal de Minas Gerais (UFMG).

## Proposta
Willie Gates  é o CEO de uma grande rede social chamada LinkOut. No entanto, a rede está enfrentando uma grande crise e ele está buscando maneiras de aumentar o engajamento dos usuários. O principal objetivo da LinkOut é conectar seus usuários às vagas de emprego ideais. Infelizmente,
Willie está recebendo muitas reclamações de usuários que não estão sendo recomendados para nenhuma vaga, enquanto seus colegas com qualificações semelhantes estão sendo bombardeados com novas vagas.

Desesperado, Willie contatou você, um especialista em algoritmos, para desenvolver uma solução que pudesse garantir vagas para o máximo de usuários possível, a fim de evitar os problemas relatados pelos usuários da rede. Felizmente, Willie possui um algoritmo muito eficaz que indica se um usuário é apto ou não para determinada vaga. Esses dados podem ser representados como um grafo bipartido, onde uma aresta candidato-vaga existe se o candidato atende aos requisitos da vaga.

Preocupado com a rápida queda de usuários da LinkOut, você sugeriu utilizar uma espécie de *Proof of Concept* para o problema, propondo uma abordagem gulosa, de baixa complexidade, que encontra uma solução rapidamente. Willie aprovou a ideia, desde que, assim que a solução gulosa estiver pronta, você também implemente um outro algoritmo que sempre encontre a melhor solução possível.

Sua missão é implementar dois algoritmos que encontrem pares únicos de usuários e vagas para o maior número possível de usuários em uma rede. Note que a solução gulosa muitas vezes é subótima, e Willie gostaria que você comparasse ambas soluções, apontando para ele as vantagens e desvantagens de cada algoritmo.

---
## Modelagem do problema
Este trabalho prático aborda a parte de grafos e algoritmos gulosos da ementa desta disciplina. Para a resolução do problema a sua modelagem precisa usar ambas técnicas e deve ser descrita sucintamente no relatório apresentado.