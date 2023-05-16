

# Programming for ICT" working repo.

NOTE: MY REPOSITORY ARE second_exam & test ...
NOTE: This code works ONLY with Linux an macOS. NO SUPPORT FOR WINDOWS

HOW-TO setup your system
Compiler: be sure to have at least g++ 5.4 or a newer version. 
(You can check by typing in your shell `g++ -v`.)
Install the following packages, by typing in your shell:
* if Debian-based, such as (X/K)Ubuntu, Mint, ect:
```
sudo apt-get install build-essential autoconf automake libxmu-dev libx11-dev libxmu-dev libxmu-headers libxt-dev libtool gfortran bison flex
```
* if Red-Hat-based (Fedora, CentOS):
```
dnf groupinstall "C Development Tools and Libraries"
dnf install gcc-fortran libXmu-devel libX11-devel patch patchutils
``` 

HOW-TO get and compile the code:
* open a Linux (or MAC) shell
* clone the gitlab repo (with HTTPS) by typing:
```
git clone https://gitlab.dei.unipd.it/programming-for-telecommunications2223/programming-for-tlc-exam-16-2-2023.git
```
* go to the installer directory, by typing:
```
cd programming-for-tlc-exam-16-2-2023/autotools-structure/
```
* in the computers of the lab (room Da at DEI), you need to select the correct version of the C++ compiler with the command
```
scl enable devtoolset-7 bash
```
* install the code, by typing:
```
./installer.sh -p /home/<your_home>/ -t 1
```
SUBSTITUTE `<your_home>` with your actual home folder, i.e., if your account is 
pippo, you have to type:
```
./installer.sh -p /home/pippo/ -t 1
```



"ADVANCED" STUFF WILL FOLLOW, STOP HERE IF THIS IS THE FIRST TIME YOU INSTALL 
THE CODE


See you all in class,

Michele and Filippo

Notes on the installer:
* the `installer.sh` script is provided with the following options:
	```
	OPTIONS:
	   -h    Show this message
	   -p    Prefix Path
	   -t    Test enable (1) or disable (0, default)
	   -c    clean repository
	```
so you instead of in your home folder, you can decide to install it somewhere else 
(e.g., in a subdirectory of your home folder).

Notes on GIT:

* HOWTO clone the repo (with HTTPS):
```
git clone https://gitlab.dei.unipd.it/programming-for-telecommunications2223/programming-for-tlc-exam-16-2-2023.git
```
* The master branch is protected: please clone the repo and then work in your own branch.
* In order to change your branch, type:
```
git checkout -b <my-username>-<branch-name>
```
where you substitute
	- `<my-username>` with your user name, and 
	- `<branch-name>` with a meaningful branch name
* now you can commit your changes with
```
git add <file1> <file2> <file3> ..
git commit -m "your message that means something"
```
* in the case you want to push the branch to remote (let everyone see what you 
did so far), just type 
```
git push origing <my-username>-<branch-name>
```
* You can now create a merge request, assigning the code review to someone.
* To update your branch with the remote (if someone else pushed on it), type:
```
git pull origin <my-username>-<branch-name>
```

