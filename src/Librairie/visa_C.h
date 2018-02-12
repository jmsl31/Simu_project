//---------------------------------------------------------------------------
#ifndef visa_CH
#define visa_CH
#include <string>
#include <visa.h>
#include <visatype.h>

#define BUFFER_LENGTH               20240

#define VISA_ERR_VISA_CLASS         "VISA"

#define VISA_ERR_INTER_RESPONSE     1
#define VISA_ERR_DETECTED_BY_INSTR  2

#ifndef linux
#include <Classes.hpp>
#endif

//---------------------------------------------------------------------------

using namespace std;

typedef ViStatus (__stdcall *PTR_FUNCTION_viOpenDefaultRM)(ViPSession vi);
typedef ViStatus (__stdcall *PTR_FUNCTION_viOpen)(ViSession sesn, ViRsrc name, ViAccessMode mode, ViUInt32 timeout, ViPSession vi);
typedef ViStatus (__stdcall *PTR_FUNCTION_viClose)(ViObject vi);
typedef ViStatus (__stdcall *PTR_FUNCTION_viSetAttribute)(ViObject vi, ViAttr attrName, ViAttrState attrValue);
typedef ViStatus (__stdcall *PTR_FUNCTION_viGetAttribute)(ViObject vi, ViAttr attrName, void _VI_PTR attrValue);
typedef ViStatus (__stdcall *PTR_FUNCTION_viStatusDesc)(ViObject vi, ViStatus status, ViChar _VI_FAR desc[]);
typedef ViStatus (__stdcall *PTR_FUNCTION_viRead)(ViSession vi, ViPBuf buf, ViUInt32 cnt, ViPUInt32 retCnt);
typedef ViStatus (__stdcall *PTR_FUNCTION_viWrite)(ViSession vi, ViBuf  buf, ViUInt32 cnt, ViPUInt32 retCnt);
typedef ViStatus (__stdcall *PTR_FUNCTION_viPrintf)(ViSession vi, ViString writeFmt, ...);
typedef ViStatus (__stdcall *PTR_FUNCTION_viQueryf)(ViSession vi, ViString writeFmt, ViString readFmt, ...);
typedef ViStatus (__stdcall *PTR_FUNCTION_viScanf)(ViSession vi, ViString readFmt, ...);
typedef ViStatus (__stdcall *PTR_FUNCTION_viReadSTB)(ViSession vi, ViPUInt16 status);
typedef ViStatus (__stdcall *PTR_FUNCTION_viClear)(ViSession vi);
typedef ViStatus (__stdcall *PTR_FUNCTION_viEnableEvent)(ViSession vi, ViEventType eventType, ViUInt16 mechanism,
                                    ViEventFilter context);
typedef ViStatus (__stdcall *PTR_FUNCTION_viDisableEvent)(ViSession vi, ViEventType eventType, ViUInt16 mechanism);
typedef ViStatus (__stdcall *PTR_FUNCTION_viDiscardEvents)(ViSession vi, ViEventType eventType, ViUInt16 mechanism);
typedef ViStatus (__stdcall *PTR_FUNCTION_viWaitOnEvent)(ViSession vi, ViEventType inEventType, ViUInt32 timeout,
                                    ViPEventType outEventType, ViPEvent outContext);
typedef ViStatus (__stdcall *PTR_FUNCTION_viFlush)(ViSession vi, ViUInt16 mask);
typedef ViStatus (__stdcall *PTR_FUNCTION_viSetBuf)(ViSession vi, ViUInt16 mask, ViUInt32 size);

static PTR_FUNCTION_viOpenDefaultRM viOpenDefaultRM_s = NULL;

static PTR_FUNCTION_viOpen viOpen_s = NULL;
static PTR_FUNCTION_viClose viClose_s = NULL;
static PTR_FUNCTION_viSetAttribute viSetAttribute_s = NULL;
static PTR_FUNCTION_viGetAttribute viGetAttribute_s = NULL;
static PTR_FUNCTION_viFlush viFlush_s = NULL;
static PTR_FUNCTION_viStatusDesc viStatusDesc_s = NULL;
static PTR_FUNCTION_viRead viRead_s = NULL;
static PTR_FUNCTION_viWrite viWrite_s = NULL;
static PTR_FUNCTION_viPrintf viPrintf_s = NULL;
static PTR_FUNCTION_viQueryf viQueryf_s = NULL;
static PTR_FUNCTION_viScanf viScanf_s = NULL;
static PTR_FUNCTION_viReadSTB viReadSTB_s = NULL;
static PTR_FUNCTION_viClear viClear_s = NULL;
static PTR_FUNCTION_viEnableEvent viEnableEvent_s = NULL;
static PTR_FUNCTION_viDisableEvent viDisableEvent_s = NULL;
static PTR_FUNCTION_viDiscardEvents viDiscardEvents_s = NULL;
static PTR_FUNCTION_viWaitOnEvent viWaitOnEvent_s = NULL;
static PTR_FUNCTION_viSetBuf viSetBuf_s = NULL;

/**
 * Classe des exceptions VISA.
 */
class error_Ex
{
public:

    /**
     * Variable membre contenant une chaine de string définissant l'erreur.
     */
    string erreurStr;

    /**
     * Variable membre contenant le numéro du code erreur.
     */
    int erreurCode;

    /**
     * Exportation de l'erreur sous forme char.
     * @param errnum pointeur sur le numéro d'erreur, copie de la variable membre erreurCode.
     * @param errstr pointeur sur le premier caractère de la chaine d'erreur, copie de la variable membre erreurStr.
     */
    error_Ex(int errnum, char* errstr)
    {
    erreurStr = errstr;
    erreurCode = errnum;
    }

    /**
     * Exportation de l'erreur sous forme string.
     * @param errnum pointeur sur le numéro d'erreur, copie de la variable membre erreurCode.
     * @param errstr pointeur sur le premier caractère de la chaine d'erreur, copie de la variable membre erreurStr.
     */
    error_Ex(int errnum, string errstr)
    {
    erreurStr = errstr;
    erreurCode = errnum;
    }
};

/**
 * Classe Visa niveau carte.
 */
class visaDefaultRM_C
{
private:
    HMODULE LibId;

public:

    /**
     * Variable membre contenant le numéro de session VISA au niveau carte.
     */
    unsigned long sess_m;

    /**
     * Methode d'ouverture session VISA au niveau carte.
     */
    void OpenDefaultRm();

    /**
     * Methode de fermeture session VISA au niveau carte.
     */
    void CloseDefaultRm();
};

/**
 * Classe Visa niveau instrument.
 */
class visa_C
{
private:

    /**
     * Variable membre privée définissant le mode de fonction en debug ou normal.
     */
    bool debug_m;

    /**
     * Variable membre privée définissant avec quel ressource (instrument), le dialogue s'effectue.
     */
    string visaRessource_m;

    /**
     * Cette variable membre va permettre de savoir si la session VISA est close pour
     * l'appareil concerné.
     */
    bool deviceClosed_m;

public:

    /**
     * Variable membre privée contenant le numéro de session VISA au niveau instrument.
     */
    unsigned long session_m;            //Numero de session instrument

    /**
     * Ouverture session instrument.
     * @param viRM pointeur sur la session VISA d'accés à la carte GPIB.
     * @param instr_i pointeur sur le premier caractère de l'adresse de l'instrument.
     */
    void Open(visaDefaultRM_C *viRM, char instr_i[]);

    /**
     * Lecture en binaire.
     * @param buf_i pointeur sur le buffer retourné par la fonction.
     * @param sizeBuf_i paramètre d'entrée définissant la longeur du buffer alloué en entrée de la fonction.
     * @param retCnt_i pointeur sur le nombre de caractères retournés par la fonction.
     */
    void ReadBinary(char *buf_i, long sizeBuf_i, unsigned long *retCnt_i);

    /**
     * Lecture en ASCII sous la forme string.
     * @param data_i pointeur sur la chaine de string retournée par la fonction.
     */
    void ReadAscii(string *data_i);

    /**
     * Lecture en ASCII sous la forme char.
     * @param data_i pointeur sur le premier caractère de la chaine de string retournée par la fonction.
     * @param bufferLength_i paramètre d'entrée définissant la longeur du buffer alloué en entrée de la fonction.
     */
    void ReadAscii(string *data_i, unsigned int bufferLength_i);

    /**
     * Ecriture en binaire.
     * @param data_i pointeur sur le premier caractère à envoyer par la fonction.
     * @param size_i paramètre d'entrée définissant la longeur de la chaine en entrée de la fonction.
     */
    void WriteBinary(const char *data_i, int size_i);

    /**
     * Ecriture en ASCII sous la forme string.
     * @param data_i paramètre d'entrée définissant la chaine de string en entrée de la fonction.
     */
    void WriteAscii(const string *data_i);

    /**
     * Ecriture en ASCII sous la forme char.
     * @param data_i pointeur sur le premier caractère de la chaine de char en entrée de la fonction.
     */
    void WriteAscii(const char *data_i);

    /**
     * Effacement.
     */
    void Clear();

    /**
     * Lecture de l'octet de status, retourne un long.
     */
    long ReadSTB();

    /**
     * Fermeture session instrument.
     */
    void Close();

    /**
     * Ecriture des attributs.
     * @param attr_i paramètre d'entrée définissant l'attribut à manipuler.
     * @param attrstate_i paramètre d'entrée définissant l'état à donner à l'attribut.
     */
    void SetAttribute(long attr_i, long attrstate_i);

    /**
     * Lecture des attributs.
     * @param attr_i paramètre d'entrée définissant l'attribut à manipuler.
     */
    void GetAttribute(long attr_i, void _VI_PTR attrstate_i);

    /**
     * Gestion du mack.
     * @param mask_i paramètre d'entrée définissant le mask.
     */
    void Flush(long mask_i);

    /**
     * Ecriture du buffer.
     * @param mask_i paramètre d'entrée définissant le mask.
     */
    void SetBuf(long mask_i, long size_i);

    /**
     * Attente.
     * @param Delay_ms_i paramètre d'entrée optionnel définissant la durée de l'attente en ms, par défaut cette durée est de 100ms.
     */
    void Wait(int Delay_ms_i = 100);

    /**
     * Attente fin d'opération instrument.
     * @param Timeout_ms_i paramètre d'entrée optionnel définissant la durée de l'attente en ms avant de remonter un timeout, par défaut cette durée de timeout est de 5min.
     */
    void OperationComplete(int Timeout_ms_i = 300000);

    /**
     * Activation / désaction debug.
     * @param debug_i paramètre d'entrée optionnel définissant si on est en mode debug ou pas, par défaut la couche VISA fonctionne en mode debug.
     */
    void setDebug(bool debug_i = true);

    /**
     * Positionnement du time-out de reception des donnees
     * @param timeOutMs time-out en milliseconde
     */
    virtual void SetTimeOutMs(long timeOutMs);

    /**
     * Destructeur, fermeture implicite de session de carte.
     */
    ~visa_C();

    /**
     * Constructeur par défaut.
     */
    visa_C();

    ViStatus viSetAttribute(long attr_i, ViAttrState attrstate_i);
    ViStatus viGetAttribute(long attr_i, void _VI_PTR attrstate_i);
    ViStatus viRead(ViPBuf buf, ViUInt32 cnt, ViPUInt32 retCnt);
    ViStatus viWrite(ViBuf  buf, ViUInt32 cnt, ViPUInt32 retCnt);
    ViStatus viPrintf(ViString writeFmt, void _VI_PTR param);
    ViStatus viQueryf(ViString writeFmt, ViString readFmt);
    ViStatus viQueryf(ViString writeFmt, ViString readFmt, void _VI_PTR param);
    ViStatus viQueryf(ViString writeFmt, ViString readFmt, void _VI_PTR param, void _VI_PTR param2);
    ViStatus viScanf(ViString readFmt, void _VI_PTR param);
    ViStatus viStatusDesc(ViStatus status, ViChar _VI_FAR desc[]);
    ViStatus viReadSTB(ViPUInt16 status);
    ViStatus viFlush(ViUInt16 mask);

};
//----------------------------------------------------------------------------
#endif

