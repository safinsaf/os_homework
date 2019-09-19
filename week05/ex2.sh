file="ex2_file"
lock="ex2.lock"

while true
do
    if (ln -s $file $lock);           #check if exists
    then
        if [ -s $file ]               #check if nonempty
        then
            line=$( tail -n 1 $file )
            echo $(($line+1))>>$file
        else                          #if empty
            echo "1">$file
        fi
        rm $lock
    fi
done

