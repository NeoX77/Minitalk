# 🖱 42Paris Project | minitalk

## Objectives

The goal of this project is to send a message to a server using only unix signals SIGUSR1 and SIGUSR2.  
We have to do a client and a server in C that will receive using signal() and sigaction() functions to send messages to each other.  

![image](https://user-images.githubusercontent.com/16923245/235344674-93925d7c-a032-450e-b432-e7b5abab5005.png)

## Usage

`make` to compile the programs.  
`clean` to clean objects files.  
`fclean` to clean objects files and program files.  

Start by launching the server program  
**Execute**: `./server`  
The server will print his pid (used by the client program to send unix signals)  

Next, launch the client program with the pid and a message to send  
**Execute**: `./client <pid> <message>`  
If the server has received the message, the client will be notified. (It's a part of the bonus)

## Help

To send a message we have to translate all caracters one by one, because we can use only SIGUSR1 and SIGUSR2, we can translate this ones by the bit '0' and '1'. In this way, we can translate all characters by its bits value and send all bits one by one to the server. When the message is finished, a \0 is send then the server will receive only '0' bits, it marks the end of the message.  

On MacOS the signals are put in queue so we can just send signals in a loop to comunicate with the server.  

On linux OS the unix signals are not put in a queue and to do this project we have to make a 'ping pong' with signals between the two process. The first which send a signal is the client, then the server, once the server receive a signal, it send in its turn a signal to the client to tell "It's okay, send me the next signal", this method is well recommendend to be sure that signals are not mixed.

## Score

[![wdebotte's 42 FdF Score](https://badge42.vercel.app/api/v2/cl2zu1sil002509mf9zd91hy6/project/2451229)](https://github.com/JaeSeoKim/badge42)
