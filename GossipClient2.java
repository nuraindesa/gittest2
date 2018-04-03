import java.net.InetAddress;

import java.net.UnknownHostException;

import java.io.*;

import java.net.*;

import java.util.Date;

public class GossipClient2
{
public static void main(String[] args) throws Exception
{
	Socket sock=new Socket ("192.168.174.132",26272);
	
	BufferedReader keyRead=new BufferedReader(new InputStreamReader(System.in));
	
	OutputStream ostream= sock.getOutputStream();
	PrintWriter pwrite= new PrintWriter(ostream,true);

	InputStream istream=sock.getInputStream();
	BufferedReader receiveRead =new BufferedReader(new InputStreamReader(istream));
	
	Date d=new Date();

	try {

      InetAddress inetAddress = InetAddress.getLocalHost();

      System.out.println("IP Address: "+inetAddress.getHostAddress());

      System.out.println("Hostname: "+inetAddress.getHostName());

    }catch(UnknownHostException unknownHostException){

      unknownHostException.printStackTrace();

    }	
	
	String s="Current Date & Time on Client is:"+d;
	System.out.println(s);	

	        BufferedReader fromserver=new BufferedReader(new 
InputStreamReader(sock.getInputStream()));

        

        System.out.println(fromserver.readLine());

	System.out.println ("Start chat now ");
	
	String receiveMessage, sendMessage;
	
	while (true)
	{
		sendMessage=keyRead.readLine();
		System.out.println("client : " + sendMessage);
		pwrite.println(sendMessage);
		pwrite.flush();
	if((receiveMessage = receiveRead.readLine())!=null)
	{
		System.out.println("server : " + receiveMessage);
		}
	}
	}
}

