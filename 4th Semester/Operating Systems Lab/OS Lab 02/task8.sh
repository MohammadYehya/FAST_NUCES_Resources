if [[ ! -d /home/$USER/Desktop/jpgdir ]]; then mkdir /home/$USER/Desktop/jpgdir; fi
if [[ ! -d /home/$USER/Desktop/cdir ]]; then mkdir /home/$USER/Desktop/cdir; fi
if [[ ! -d /home/$USER/Desktop/shelldir ]]; then mkdir /home/$USER/Desktop/shelldir; fi

read -p "Enter the Directory to sort: " dir
if [[ -d $dir ]];
then
	cd
	cd $dir
	for File in *
	do
		case $File in
			*.jpg) sudo mv $File /home/$USER/Desktop/jpgdir;echo "Moved $File";;
			*.c) sudo mv $File /home/$USER/Desktop/cdir;echo "Moved $File";;
			*.sh) sudo mv $File /home/$USER/Desktop/shelldir;echo "Moved $File";;
		esac
	done
	echo ".jpg, .c, .sh files have been moved to /home/$USER/Desktop folders: jpgdir, cdir, shelldir"
else echo "Directory does not exist!"
fi
