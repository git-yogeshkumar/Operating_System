package producerconsumer;
import java.util.Scanner;
class producer_consumer{
     int x=1;
     int e=5;
     int f=0;
     int wait(int x)
    {
        --x;
        return x;
    }
    int signal(int x)
    {
        ++x;
        return x;
    }
     void producer()
    {
        x=wait(x);
        f=signal(f);
        e=wait(e);
        System.out.println("Producer has produced");
        x=signal(x);
        
    }
    void consumer()
    {
        x=wait(x);
        f=wait(f);
        e=signal(e);
        System.out.println("Costumer has Consumed");
        x=signal(x);
    }
    
        producer_consumer()
        {
        String c;
        do
        {
            System.out.println("1.Producer 2.Consumer 3.Exit");
            int ch;
            Scanner s=new Scanner(System.in);
            ch=s.nextInt();
            switch(ch)
            {
                case 1:
                {
                    if(x==1&&f!=5)
                    {
                        producer();
                    }
                    else
                    {
                        System.out.println("Producer Waiting...");
                       
                    }
                    break;
                }
                case 2:
                {
                    if(x==1&&e!=5)
                    {
                        consumer();
                    }
                    else
                    {
                        System.out.println("Consumer Waiting...");
                       
                    }
                    break;
                } 
                case 3:
                {
                System.exit(0);
                }
                }
            System.out.println("Do you want to continue(y/n)");
            c=s.next();
        }while(c.equalsIgnoreCase("y"));
        }
}
public class ProducerConsumer {
    public static void main(String[] args) {
        new producer_consumer();
    }
    
}
