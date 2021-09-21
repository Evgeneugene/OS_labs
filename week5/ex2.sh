if test ! -f file.txt
then
    echo 0 > file.txt
fi

if ln file.txt file.txt.lock
	then                                                                    
	for i in {1..100};
	do
		last=`tail -1 file.txt`
		last=$((last+1))
		echo $last >> file.txt
	done
	rm file.txt.lock
fi