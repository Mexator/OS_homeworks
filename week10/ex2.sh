#Create file & link
touch ../week1/file.txt >> ex2.txt
link ../week1/file.txt _ex2.txt >> ex2.txt
#Get inode number 
INODE=$(ls -i ../week1/file.txt | grep -oE ^[0-9]+) >> ex2.txt
#Finding & removing
find ../ -inum $INODE >> ex2.txt
find ../ -inum $INODE -exec rm {} \; >> ex2.txt