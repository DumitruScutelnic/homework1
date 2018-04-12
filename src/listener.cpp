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
#include <string>
#include <sstream>
#include "homework1/messaggio.h"

using namespace std;

static std::string comando;
void msgSplitter(const homework1::messaggio& msg);

void msgComand(const std_msgs::String::ConstPtr& msg)
{
  //cout << "comand" << endl;
  ROS_INFO("Comando ricevuto: [ %s ]", msg->data.c_str());
  std::string reads = msg->data.c_str();
  comando = reads;
}

void msgSplitter(const homework1::messaggio& msg)
{ 
  if(comando[0] == 'a')
  {
    ROS_INFO("[%s, %s, %s]", msg.nome.c_str(), msg.eta.c_str(),msg.corso.c_str());
  }else if(comando[0] == 'n'){
    ROS_INFO("[ %s ]", msg.nome.c_str());
  }else if(comando[0] == 'e'){
    ROS_INFO("[ %s ]", msg.eta.c_str());
  }else if(comando[0] == 'c'){
    ROS_INFO("[ %s ]", msg.corso.c_str());
  }else{
    cout << "riprova..." << endl; 
  }
}
// %EndTag(CALLBACK)%

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
  ros::init(argc, argv, "listener");

/**
 * NodeHandle is the main access point to communications with the ROS system.
 * The first NodeHandle constructed will fully initialize this node, and the last
 * NodeHandle destructed will close down the node.
 */
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, msgSplitter);
  ros::Subscriber con = n.subscribe("command", 1000, msgComand);
  ros::spin();
  
  
  
  
  return 0;
}
// %EndTag(FULLTEXT)%
