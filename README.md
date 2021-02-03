# Calendário PDF

## Funcionalidades:
  - Imprimir calendário como lista
  - Imprimir calendário como PDF
  - Consultar Eventos
  
## Dicas de Uso:
  -Ao executar o programa, deve-se inserir o NÚMERO das opções a serem selecionadas no terminal
  -Para obter o endereço do arquivo de eventos, clique com o botão direito sobre o arquivo e clique em propriedades. Selecione a aba 'Segurança' e copie o 'Nome do objeto'
  -Caso crie um arquivo de eventos, os eventos devem ser inseridos linha a linha segundo o exemplo: A 4 8 0 Anastacia
  -Quando o dia, mês ou ano forem nulos, o programa entende que se repete todo dia, mês ou ano. No exemplo do item acima, o programa entende que o evento se repete todo ano no dia 4 de Agosto
 
 ## Components:
    Existem alguns arquivos .jpg nesse programa. Esses arquivos contribuem na montagem do PDF.
    -Os arquivos pdfgen.h e pdfgen.c são uma biblioteca que pode ser encontrada no link: https://github.com/AndreRenaud/PDFGen
    -Os arquivos Funções.c e Biblioteca.h contém as funções que realizam a parte funcional do programa
    -O arquivo main.c realiza a interação com o usuário
    
## Executable
  É o programa já compilado. Basta executar o arquivo .exe
  
## Exemplo.txt
  É um arquivo de eventos que pode ser usado para testar o programa
