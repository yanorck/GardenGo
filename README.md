# GardenGo

GardenGo é uma DSL (Domain-Specific Language) projetada para automatizar e orquestrar as tarefas de um jardim inteligente de forma simples e intuitiva. Com uma sintaxe inspirada em linguagens imperativas, ela permite:

Definir zonas de cultivo e trabalhar com coordenadas para organizar diferentes áreas da horta

Plantar, regar, fertilizar, podar e colher espécies específicas

Esperar tempos configuráveis (WAIT 10s, WAIT 5m, etc.)

Criar laços de repetição (LOOP 3 TIMES { … }) para automatizar ciclos sazonais

Fazer decisões condicionais com base em sensores de umidade, temperatura ou clima (IF SOIL_MOISTURE < 30% THEN WATER)

Monitorar sensores distribuídos por coordenadas para acionar ações pontuais

Ideal para projetos de jardinagem de hobby, protótipos de automação residencial ou simplesmente para brincar com linguagens específicas de domínio, o GardenGo facilita a tradução de planos de cuidado com plantas em scripts legíveis e fáceis de manter. Basta escrever seu .garden e deixar o parser/interpretador executar todo o ciclo de manutenção do seu jardim!
