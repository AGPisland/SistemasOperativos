#include "procesos2.cpp"
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
void avanzar();

int main(){
	
	string user_op, log;
	int user_num;
	
	cout<<"MULTIPROCESOS"<<endl;
	system("pause");
		
	inicializar_rq();
	
	while(true){
		system("cls");
				
		cout<<endl; imprimir_rq();cout<<endl;
		
		cout<<"Cantidad de procesos de la ready Queue: "<<get_p_count()<<endl;
		cout<<"Cantidad de procesos en la wait Queue: "<<wait_q.size()<<endl;
		cout<<endl<<">> Para ayuda, ingrese -help <<"<<endl<<endl;
		
		//listar procesos
		
		//user input
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
		
		//avanzar
		if(user_op == c_avanzar){
			av_procesos();
			continue;
		}
		
		//insertar sin avanzar (solo a la wait Q)
		if(user_op == c_ins_no_adv){
			cout<<">>Ingrese el Tiempo de Ejecucion del proceso: ";
			cin>>user_num;
			if(user_num<=0){user_num=1;}
			ingresar_p(user_num);
			continue;
		}
		
		//insertar con avanzar
		if(user_op == c_insertar){
			//ingresar thread
			cout<<">>Ingrese el Tiempo de Ejecucion del proceso: ";
			cin>>user_num;
			if(user_num<=0){user_num=1;}
			ingresar_p(user_num);
			
			//llenar ready_Q
			mover_procesos();
			
			//avanzar sistema
			av_procesos();
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

