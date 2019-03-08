# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestles <drestles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 23:51:32 by pcollio-          #+#    #+#              #
#    Updated: 2019/03/08 20:20:39 by drestles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rmout()
{
	rm ../ft_ls.out
	rm ../ls.out
}

cmpdiff()
{
	diff -U 3 ../ls.out ../ft_ls.out > out.txt
	if [ $? -ne 0 ]; then
	    echo "${ROUGE}[KO]${RESETCOLOR} DIFF KO";
	else
		echo "${VERT}[OK]${RESETCOLOR} DIFF OK"
	fi
}

printdebug()
{
	if [ $PRINTDEBUG -eq 1 ]
	then
		echo "${CYAN}DEBUG :${RESETCOLOR}"
		if [ -s out.txt ]
		then
			cat out.txt
		else
			echo " DIFF output is empty :)"
		fi
	fi
}

dotest()
{
	cmpdiff
	printdebug
	# rmout
	# rm -rf *
}

################### TEST 1 #######################
cd testdir
touch file1 zfile2 yfile3
mkdir gdir adir ndir
cd ..
echo "${BLEU}test_01_simple >>${RESETCOLOR}"
ls testdir > ../ls.out
${PATH_TO_LS}ft_ls testdir > ../ft_ls.out
dotest
######################################################

# ################### TEST 2 #######################
# touch file1 zfile2 yfile3
# mkdir gdir adir ndir
# touch gdir/file1
# echo "${BLEU}test_02_simple >>${RESETCOLOR} "
# ls zfile2 gdir ndir yfile3  > ../ls.out
# ${PATH_TO_LS}ft_ls zfile2 gdir ndir yfile3 > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 3 #######################
# touch file1 zfile2 yfile3
# mkdir gdir adir ndir
# touch gdir/file1 adir/filefile
# ln -s gdir symdir
# ln -s adir asymdir
# ln -s adir/filefile symfile1
# echo "${BLEU}test_03_simple >>${RESETCOLOR} "
# ls > ../ls.out
# ${PATH_TO_LS}ft_ls > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 4 #######################
# touch file1 zfile2 yfile3
# mkdir gdir adir ndir
# touch gdir/file1 adir/filefile
# ln -s gdir symdir
# ln -s adir asymdir
# ln -s adir/filefile symfile1
# echo "${BLEU}test_04_simple >>${RESETCOLOR} "
# ls symdir gdir asymdir adir file1 yfile3 > ../ls.out
# ${PATH_TO_LS}ft_ls symdir gdir asymdir adir file1 yfile3 > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 5 #######################
# cd testdir
# touch file1 file2 file3 file4 file5 file6 file7 file8
# mkdir gdir
# chmod 117 file1
# chmod 100 file2
# chmod 777 file3
# chmod 333 file4
# chmod 222 file5
# chmod 111 file6
# chmod 333 file7
# chmod 666 file8
# echo "${BLEU}test_05_l_perm_simple >>${RESETCOLOR} "
# ls -1l > ../ls.out
# ${PATH_TO_LS}ft_ls -l > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 6 #######################
# touch file1 file2 file3 file4
# mkdir gdir
# touch -t 202001011100 file1
# touch -t 199401012200 file2
# touch -t 201801012200 file3
# touch -t 201712241030 file4
# touch -t 201712110930 gdir
# echo "${BLEU}test_06_l_date_simple >>${RESETCOLOR} "
# ls -1l > ../ls.out
# ${PATH_TO_LS}ft_ls -l > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 7 #######################
# mkfifo pipe1
# python -c "import socket as s; sock = s.socket(s.AF_UNIX); sock.bind('somesocket')"
# echo "${BLEU}test_07_l_filetype_simple >>${RESETCOLOR} "
# ls -1l /dev/ | cut -c 1-10 > ../ls.out
# ${PATH_TO_LS}ft_ls -l /dev/ | cut -c 1-10 > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 8 #######################
# echo "${BLEU}test_08_l_filetype_hard >>${RESETCOLOR} "
# ls -1l /dev/ | cut -c 1-10 > ../ls.out
# ${PATH_TO_LS}ft_ls -l /dev/ | cut -c 1-10 > ../ft_ls.out
# dotest
# ######################################################

# ################### TEST 9 #######################
# echo "${BLEU}test_09_l_manydir_simple >>${RESETCOLOR} "
# ls -1l ~/ / > ../ls.out
# ${PATH_TO_LS}ft_ls -l ~/ / > ../ft_ls.out
# dotest
# ######################################################