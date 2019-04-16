#!/bin/bash

main()
{
	files=`ls | grep cpp`
	for file in $files
		do 
			ofile=$file
			
			file=`echo $file | cut -d"." -f1`
			len=${#file}
			file=${file:0:(($len-2))}
			dir=UVa$file
			
			[ ! -d $dir ] && mkdir $dir
			echo -e "mv $ofile $dir"
			mv $ofile $dir
		done

}

main 

