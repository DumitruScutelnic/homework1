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

#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
// %EndTag(MSG_HEADER)%

#include <sstream>
#include "homework1/messaggio.h"

int main(int argc, char **argv)
{
// %Tag(INIT)%
  ros::init(argc, argv, "talker");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

// %Tag(PUBLISHER)%
  ros::Publisher chatter_pub = n.advertise<homework1::messaggio>("chatter", 1000);
// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(1); //1 Hz = 1 volta al sec 
// %EndTag(LOOP_RATE)%

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
// %Tag(ROS_OK)%
// %Tag(FILL_MESSAGE)%
    //std_msgs::String msg;
    homework1::messaggio msg;
    std::stringstream nome; 
    nome << "Dumitru";
    msg.nome = nome.str();

    std::stringstream eta;
    eta << "25";
    msg.eta = eta.str();

    std::stringstream corso;
    corso << "Laurea magistrale in Molecular and medical biotechnology";
    msg.corso = corso.str();
    
// %EndTag(FILL_MESSAGE)%

  //int count = 0;
  while (ros::ok())
  {
// %EndTag(ROS_OK)%
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
// %Tag(ROSCONSOLE)%
    ROS_INFO("Nome: %s, Eta: %s, Corso: %s", msg.nome.c_str(),msg.eta.c_str(),msg.corso.c_str());
// %EndTag(ROSCONSOLE)%

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
// %Tag(PUBLISH)%
    chatter_pub.publish(msg);
// %EndTag(PUBLISH)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
  }


  return 0;
}
// %EndTag(FULLTEXT)%
