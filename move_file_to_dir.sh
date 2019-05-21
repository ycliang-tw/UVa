#!/bin/bash
#######################################################################
# The difference between "if []; then" and "[] &&/|| instruction" is ##
# that the execution result($?) of the former will always be true    ##
#######################################################################


DRY_RUN=0

function usage()
{
	echo "usage: ./move_file_to_dir [option] [problem ID]"
	echo "    -i, --ID <problem ID>        Only move the specified file."
	echo "    -v, --invert <problem ID>    Only the specified file will not be moved."
	echo "    -d, --dry-run                Do not really move the files, only shows what actions will be done."
	echo "    -h, --help                   Show this message. "
	echo "Default action is to move all the files to their corresponding directory"
}

function move_file_to_dir()
{
	
	files=`ls | xargs -n 1 | grep -e cpp -e c`
	
	if [ "$ONLY_MV" = "1" ]; then
		files=`ls | grep -e cpp -e c | grep $ID`
	elif [ "$ONLY_NOT_MV" = "1" ]; then
		files=`ls | grep -e cpp -e c | grep -v $ID`
	fi

	for file in $files
		do 
			origin_file=$file
			
			tmp=`echo $file | cut -d"." -f1`
			len=${#tmp}
			ID=${tmp:0:(($len-2))}
			dir=UVa$ID
			
			echo -e "mv $origin_file $dir"
			if [ "$DRY_RUN" != "1" ]; then
				[ ! -d $dir ] && mkdir $dir && echo -e "mkdir $dir"
				mv $origin_file $dir
			fi
		done
}

function main()
{
	until [ -z "$1" ]
	do
		case "$1" in
			-h | --help)
				usage
				exit 0;;

			-d | --dry-run)
				DRY_RUN=1
				shift 1;;

			-i | --ID)
				shift 1
				ID=$1
				ONLY_MV=1
				break;;

			-v | --invert)
				shift 1
				ID=$1
				ONLY_NOT_MV=1
				break;;
			*)
				usage
				exit 1;;
		esac
	done

	move_file_to_dir
}

main "$@"
