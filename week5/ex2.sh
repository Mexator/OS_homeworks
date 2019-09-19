touch file.txt

if ln file.txt file.lock
then
echo 1 >> file.txt
rm file.lock
fi

while true
do
if ln file.txt file.lock
then
last_str=$(tail -n 1 file.txt)
let last_str=last_str+1
echo $last_str >> file.txt
rm file.lock
fi
sleep 1
done
