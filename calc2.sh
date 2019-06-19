#!/bin/bash

#calc2

function soma {
	echo $(( $1 + $2 ))
}


function subtra {
	echo $(( $1 - $2 ))
}

function mult {
	echo $(( $1 * $2))
}

function divi {
	echo "scale=5 ; $1 / $2" | bc
}

if [[ $# != 3 ]]
	then echo "entrada invalida"
exit 1
fi

if [[ $2 == "+" ]]
	then soma $1 $3

elif [[ $2 == "-" ]]
	then 
		subtra $1 $3
elif [[ $2 == "x" ]]
	then 
		mult $1 $3
elif [[ $2 == "/" ]]
	then 
		divi $1 $3
	else
		echo "argumentos invalidos"
		exit 1
fi
exit 0