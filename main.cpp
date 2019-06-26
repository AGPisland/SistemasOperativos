#include "procesos.cpp"
#include <cstring>

const string c_exit = "-exit";
const string c_retornar = "-ret";
const string c_reset = "-sys_rst";
const string c_insertar = "-p_ins";
const string c_ins_no_adv = "-p_ins_na";
const string c_avanzar = "-s_avz";
const string c_ayuda = "-help";

using namespace std;

void ayuda();

int main(){
	
	string user_op;
	
	cout<<"MULTIPROCESOS"<<endl;
	system("pause");
	
	while(true){
		system("cls");
		cout<<"Cantidad de nucleos: "<<core_number<<endl;
		cout<<"Cantidad de procesos de la ready Queue: "<<ready_q.size()<<endl;
		cout<<"Cantidad de procesos en la wait Queue: "<<wait_q.size()<<endl;
		cout<<endl<<">> Para ayuda, ingrese -help <<"<<endl<<endl;
		cout<<">> ";
		cin>>user_op;
		
		//salir
		if(user_op == c_exit){
			break;
		}
		
		//retornar
		if(user_op == c_retornar){
			continue;
		}
		
		//mostrar ayuda
		if(user_op == c_ayuda){
			ayuda();
			system("pause");
			continue;
		}
	}
	
	return 0;
}

void ayuda (){
	cout<<endl;
	cout<<"--Comandirijillos para el buen vecinillo--\n";
	cout<<"-----------------------------------------------\n";
	cout<<c_exit<<" cierra el programa\n";
	cout<<c_retornar<<" vuelve al principio sin avanzar\n";
	cout<<c_reset<<" elimina todos los procesos de la waitQ y la readyQ y reinicia el programa\n";
	cout<<c_insertar<<" empuja un procesos a la wait Q y luego avanza\n";
	cout<<c_ins_no_adv<<" empuja procesos a la wait Q sin avanzar el sistema\n";
	cout<<c_avanzar<<" avanza una iteracion\n";
	cout<<c_ayuda<<" muestra la ayuda\n";
	cout<<endl;
}
