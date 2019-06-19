ssh username@remote_hostname_or_IP
sftp username@remote_hostname_or_IP
scp arquivo.txt lsantos@192.168.254.92:

#!/bin/bash
echo "Seu nome de usuário é:"
whoami
echo "Info de hora atual e tempo que o computador está ligado:"
uptime
echo "O script está executando do diretório:"
pwd

echo "info do sistema: "
system_info=$(df -h) # $() executa um comando do sistema
echo “$system_info” #virou string

n string1: o comprimento de string1 é diferente de 0;
z string1: o comprimento de string1 é zero;
string1 = string2: string1 e string2 são idênticas;
string1 != string2: string1 e string2 são diferentes;
inteiro1 -eq inteiro2: inteiro1 possui o mesmo valor que inteiro2;
inteiro1 -ne inteiro2: inteiro1 não possui o mesmo valor que inteiro2;
inteiro1 -gt inteiro2: inteiro1 é maior que inteiro2;
inteiro1 -ge inteiro2: inteiro1 é maior ou igual a inteiro2;
inteiro1 -lt inteiro2: inteiro1 é menor que inteiro2;
inteiro1 -le inteiro2: inteiro1 é menor ou igual a inteiro2;
e nome_do_arquivo: verifica se nome_do_arquivo existe;
d nome_do_arquivo: verifica se nome_do_arquivo é um diretório;
f nome_do_arquivo: verifica se nome_do_arquivo é um arquivo regular (texto, imagem, programa, docs, planilhas).


##==============================================
##case
echo Selecione uma opção:
echo 1 - Exibir data e hora do sistema
echo 2 - Exibir o resultado da divisão 10/2
echo 3 - Exibir uma mensagem                                                      
read opcao
case $opcao in
	'1')
data=$(date +"%T, %d/%m/%y, %A")
echo "$data"
;;
'2')
result=$((10/2))
echo "divisao de 10/2 = $result"
;;
'3')
echo "Informe o seu nome:"
read nome;
echo "Bem-vindo ao mundo do shell script, $nome!"
;;
esac


##==============================================
##for de 10 a 0
echo “Testando o loop for”
for i in {10..0};
do
	echo “$i”
done

##==============================================
##seq de 1 a 100 a cada 5
echo “Testando o comando seq”
for i in $(seq 1 5 100);
do
	echo “$i”
done

##==============================================
##WHILE
echo “Informe o que você quiser, -1 para sair”
read dado;
while [ $dado != “-1” ];
do
	echo “Você digitou $dado”
	read dado;
done

##==============================================
##argumentos
  if [ $# -lt 1 ];
  then
   echo "Precisa fornecer pelo menos 1 argumento!"
   exit 1
 fi
 echo "Número de argumentos passados: $#"
i=0
for argumento in $*
 do
 i=$(($i+1))
  echo "Argumento $i passado: $argumento"
 done

##==============================================
##arrays
 # declaracao do array
dias=( "domingo" "segunda" "terca" "quarta" "quinta" "sexta" "sabado" );

echo ${dias[1]}; # imprime segunda

#declaracao do array
nomes[0]="paulo";
nomes[1]="ana";
nomes[2]="carlos";

echo ${nomes[1]};

# para retornar a quantidade de itens
echo ${#nomes[@]}  # imprime 3

##==============================================
##organiza

function organiza() {

  array=($@);
  i=0;
  while [ $i -lt ${#array[@]} ]; do

    j=$(($i + 1));
    while [ $j -lt ${#array[@]} ]; do

       if [ ${array[$j]} -lt ${array[$i]} ]; then

       aux=${array[$j]};
          array[$j]=${array[$i]};
          array[$i]=$aux;
       fi
       j=$(($j + 1));
    done
    i=$(($i + 1));
  done

for n in ${array[@]}; do

    echo "$n";
  done
} 