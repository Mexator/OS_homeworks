#Creating file
touch _ex3.txt
#Remove execute permission
chmod ugo-x _ex3.txt >> ex3.txt
#Grant all permissions to owner and others
chmod uo+rwx _ex3.txt >> ex3.txt
#Getting current permissions separately
cur_mode=$(stat -c %a _ex3.txt) 
u_mode=$(($cur_mode / 100))
g_mode=$u_mode
o_mode=$(($cur_mode % 10))
#Setting permissions
chmod $u_mode$g_mode$o_mode _ex3.txt