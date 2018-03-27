import java.io.*;

import java.net.*;

public class GossipClient
{
public static void main(String[] args) throws Exception
{
	Socket sock=new Socket ("192.168.173.132",26272);
	BufferedReader keyRead=new BufferedReader(new 
InputStreamReader(System.in));
OutputStream ostream= sock.getOutputStream();
PrintWriter pwrite= new PrintWriter(ostream,true);

InputStream istream=sock.getInputStream();
BufferedReader receiveRead =new BufferedReader(new 
InputStreamReader(istream));
System.out.println ("Start chat now ");
String receiveMessage, sendMessage;
while (true)
{
sendMessage=keyRead.readLine();
pwrite.println(sendMessage);
pwrite.flush();
if((receiveMessage = receiveRead.readLine())!=null)
{
System.out.println(receiveMessage);
}
}
}
}

