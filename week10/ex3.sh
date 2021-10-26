if [[ ! -f _ex3.txt ]];then
	echo Evgenii >> _ex3.txt
fi
chmod a-x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "1) rw- rw- --- :read and write for user and group
2) rwx rwx r-x (read write execute for user and group, read and execute for others)
3) rwx rwx rwx (read write execute for everyone)" >> ex3.txt