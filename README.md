# Nmap4N00bs
-------------

![Release](https://img.shields.io/badge/Release-v1.0-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge)
![Librarie](https://img.shields.io/badge/Librarie-Gtk-green?style=for-the-badge)
![Size](https://img.shields.io/github/repo-size/Oxbian/Nmap4N00bs?label=SIZE&style=for-the-badge)
![Licence](https://img.shields.io/github/license/Oxbian/Nmap4N00bs?style=for-the-badge)
![OpenSource](https://img.shields.io/badge/OpenSource-blue?style=for-the-badge&logo=opencollective&logoColor=white)

# Nmap4Noobs what it is?  
It's a simple GUI for the famous network scanning tool NMAP. Thanks to this GUI you can do all the basic commands, and you can run your own custom command too.

# How it works ?  
Just need to choose the network discovery options you want to use, the scan, and others options if you want. After that you just click on the SCAN button and that's it.  
  

- ![Screen of the applications](https://i.imgur.com/pd9w5LC.png)  
   
    
## Custom command
If you want to use custom command you just need to fill the command entry, and click on the SCAN button.
__Don't forget to add -oN output.txt, else you won't see the output__

# Compilation & installation:  

For the installation just clone the project and compile for your own computer  
__You will need GTK3 and basic C libraire for compiling the programs__:  

    git clone https://github.com/Oxbian/Nmap4N00bs.git
    cd Nmap4N00bs && make
 
__Arch & dérivés__:
    
    sudo pacman -S gtk3
__Ubuntu & Debian:__
    
    sudo apt-get install libgtk-3-0

# Contributing to the project:  
All the contribution are welcome, just do a pull request and that's it.

# License:  
This project is under GNU GPL v3.0, check the `LICENSE.md` file for more informations.

