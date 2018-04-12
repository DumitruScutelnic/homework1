/*
Un nodo pubblica, 1 volta al secondo, un messaggio contenente un nome, una età, 
e un corso di laurea
• Un nodo permette di selezionare da tastiera quale parte del messaggio verrà mostrata a video
• Un nodo mostra a video la parte del messaggio selezionata

Il nodo che permette di selezionare da tastiera quale parte
del messaggio mostrare dovrà comportarsi nel modo seguente:

Digitando ‘a’ verrà stampato tutto il messaggio
‘n’ mostrerà solo il nome
‘e’ mostrerà solo l’età
‘c’ mostrerà solo il corso di laurea
*/

// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "controller");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  ros::Publisher ms = n.advertise<std_msgs::String>("command",1000);
  ros::Rate loop_rate(1); //1 Hz = 1 volta al sec

  while(ros::ok())
  {
    //publico il menu dei comandi e lego il comando da tastiera
    cout << "Digita una dei seguenti caratteri per avere informazioni:\n‘a’ - Verrà stampato tutto il messaggio\n‘n’ - Mostrerà solo il nome\n‘e’ - Mostrerà solo l’età\n‘c’ - Mostrerà solo il corso di laure\n'q' - Exit" << endl;
    string s;
    std_msgs::String msg;
    cin >> s;//legge da tastiera
    msg.data = s;
    if(s == "q"){
        return 0;
    }else{
      ms.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }
  }
  return 0;
}
