import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Leitura{
	
	public String entDados(String rotulo){
		
		System.out.println(rotulo);
		String ret ="";
		
		InputStreamReader tec = new InputStreamReader(System.in);
		BufferedReader buffer = new BufferedReader(tec);
		
		try{
			ret = buffer.readLine();
		}
		catch(IOException ioe){
			System.out.println("\nERRO de entrada de dados");
		}
		
		return ret;
	
	}
}