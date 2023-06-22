// DEFINIÇÃO DOS PINOS UTILIZADOS
#define PINOuENERGIA	33
#define PINOuSENSORu1 	32
#define PINOuSENSORu2 	35
#define PINOuBATERIA	34
#define PINOuBOMBAu1	18
#define PINOuBOMBAu2	19
#define PINOuDHTu11     14

// VARIÁVEIS QUE DETERMINAM O TEMPO QUE O ESP IRÁ HIBERNAR
#define TENSAOuMINIMA				6.5			// VALOR EM V
#define TEMPOuHIBERNACAO          	60			// VALOR EQUIVALENTE A DEZ MINUTOS
#define MULTIPLICADORuHIBERNACAO  	10000000 	// MINUTOS
#define DEZuMINUTOS 				1
#define VINTEuMINUTOS 				2
#define TRINTAuMINUTOS 				3
#define UMAuHORA					6
#define DUASuHORAS					12
#define TRESuHORAS					18
#define QUATROuHORAS				24
const char* INICIOuSISTEMA	= "08:00:00";
const char* FINALuSISTEMA	= "18:00:00";

// DEFINIÇÃO DOS VALORES REFERENTE OS CORE'S DO ESP32
int primeiroCore = 0;
int segundoCore	 = 1;

// CREDENCIAIS PARA USO DA WIFI
const char hostName[]   = "ESP32";
const char redeWifi[]	= "NOMEuREDEuWIFI";
const char senhaWifi[] 	= "SENHAuREDEuWIFI";

// CREDENCIAIS PARA O USO DO SERVIDOR
const char* servidor 	= "ENDERECOuAPI.herokuapp.com";
const uint16_t porta 	= 80;
String caminho			= "/";

// CONTROLE PARA ENVIO E SLEEP DO SISTEMA
bool primeiraTarefaConcluida 	= false;
bool segundaTarefaConcluida  	= false;
bool terceiraTarefaConcluida	= false;

// VARIÁVEIS DE TEMPERATURA E UMIDADE DO AR
float temperatura 	= 0;
float umidadeAr		= 0;

// VARIÁVEIS NECESSÁRIAS PARA CALIBRAÇÃO DO SENSOR DE UMIDADE DO SOLO
int VALORuMAXIMOuLEITURA = 4095; 	//4095
int VALORuMINIMOuLEITURA = 0;		//1700
int AMOSTRA				 = 1000;

// VARIÁVEIS NECESSÁRIAS PARA RODAR O SISTEMA DO SENSOR 1
int PERCENTUALuSOLOuSECO = 70;

// VARIÁVEIS NECESSÁRIAS PARA RODAR O SISTEMA DO SENSOR 2
int TEMPOuPADRAO 			= 3000;
const char* DIAuSEMANA      = "0";
const char* NOVEuHORAS      = "09:00:00";
const char* DOZEuHORAS      = "12:00:00";
const char* QUINZEuHORAS    = "15:00:00";