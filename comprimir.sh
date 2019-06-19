#!/bin/bash

# Atividade 2.1

target=null
until ([ -e $target ])
do
	read -p "Qual diretorio ou arquivo deseja compactar? " target
done

compress=0
while ([[ $compress < 1 || $compress > 3  ]])
do
	read -p "Qual metodo de compressao? (1) sem compressao , (2) gzip , (3) bzip2: " compress
done

path=null
until ([ -d $path ])
do
	read -p "Onde deseja salvar o arquivo tar? " path
done

while ([ -z $filename ])
do
	read -p "Qual o nome do arquivo tar? " filename
done

if ([[ $compress == 2 ]]) # Compressor GZIP
then
	flag="z"
elif ([[ $compress == 3 ]]) # Compressor BZIP2
then
	flag="j"
else
	flag="" # sem Compressão
fi

echo "Criando arquivo tar..."
tar -c"$flag"f "$path/$filename" $target

if [ $? ]
then
	echo "Arquivo $path/$filename criado com sucesso!"
else
	echo "Falha ao criar o arquivo tar."
fi
