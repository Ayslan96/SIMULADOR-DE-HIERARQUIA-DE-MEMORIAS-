#!/bin/bash

# Atividade 2.2

function soma {
	echo $(( $1 + $2 ))
}

function subtracao {
	echo $(( $1 - $2 ))
}

function mult {
	echo $(( $1 * $2 ))
}

if [[ $# != 3 ]]
then echo "Parametros invalidos!"
	exit 1
fi

if [[ $2 == "+" ]]
then
	soma $1 $3
elif [[ $2 == "-" ]]
then
	subtracao $1 $3
:
elif [[ $2 == "*" ]]
then 
	mult $1 $3

else
	echo "Operador invalido."
	exit 1
fi

exit 0
