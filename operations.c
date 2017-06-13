
#include "dmxconfig.h"
#include "analogconfig.h"
#include "operations.h"

enum {
    OFF,
    ON,
    ADD,
    DIFF1,
    DIFF2,
    MAX,
    MIN,
    AVG,
    BACKUP,
    ANALOG,
    RX,
    CHAINED,
    SINGLE_MASTER,
    GROUPED_MASTER,
    MULTI_MASTER
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_OFF=0,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_OFF,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_OFF,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_OFF,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_OFF,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_OFF,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_OFF,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_OFF,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_OFF,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_OFF,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_OFF,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_OFF
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_ON=12,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_ON,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_ON,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_ON,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_ON,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_ON,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_ON,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_ON,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_ON,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_ON,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_ON,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_ON
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_ADD=24,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_ADD,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_ADD,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_ADD,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_ADD,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_ADD,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_ADD,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_ADD,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_ADD,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_ADD,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_ADD,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_ADD
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_DIFF1=36,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_DIFF1,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_DIFF1,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_DIFF1,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_DIFF1,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF1,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_DIFF1,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF1,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_DIFF1,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF1,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_DIFF1,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF1
};
enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_DIFF2=48,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_DIFF2,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_DIFF2,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_DIFF2,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_DIFF2,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF2,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_DIFF2,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF2,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_DIFF2,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF2,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_DIFF2,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF2
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_MAX=60,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_MAX,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_MAX,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_MAX,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_MAX,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_MAX,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_MAX,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_MAX,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_MAX,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_MAX,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_MAX,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_MAX
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_MIN_MIN=72,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_MIN,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_MIN,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_MIN,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_MIN,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_MIN,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_MIN,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_MIN,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_MIN,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_MIN,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_MIN,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_MIN
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_AVG=84,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_AVG,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_AVG,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_AVG,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_AVG,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_AVG,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_AVG,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_AVG,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_AVG,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_AVG,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_AVG,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_AVG
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_BACKUP=96,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_BACKUP,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_BACKUP,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_BACKUP,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_BACKUP,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_BACKUP,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_BACKUP,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_BACKUP,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_BACKUP,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_BACKUP,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_BACKUP,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_BACKUP
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_ANALOG=108,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_ANALOG,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_ANALOG,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_ANALOG,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_ANALOG,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_ANALOG,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_ANALOG,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_ANALOG,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_ANALOG,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_ANALOG,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_ANALOG,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_ANALOG
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_RX=120,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_RX,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_RX,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_RX,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_RX,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_RX,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_RX,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_RX,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_RX,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_RX,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_RX,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_RX
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_CHAINED=132,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_CHAINED,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_CHAINED,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_CHAINED,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_CHAINED,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_CHAINED,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_CHAINED,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_CHAINED,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_CHAINED,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_CHAINED,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_CHAINED,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_CHAINED
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_SINGLE_MASTER=144,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_SINGLE_MASTER,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_SINGLE_MASTER,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_SINGLE_MASTER,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_SINGLE_MASTER,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_SINGLE_MASTER,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_SINGLE_MASTER,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_SINGLE_MASTER,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_SINGLE_MASTER,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_SINGLE_MASTER,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_SINGLE_MASTER,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_SINGLE_MASTER
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_GROUPED_MASTER=156,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_GROUPED_MASTER,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_GROUPED_MASTER,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_GROUPED_MASTER,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_GROUPED_MASTER,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_GROUPED_MASTER,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_GROUPED_MASTER,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_GROUPED_MASTER,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_GROUPED_MASTER,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_GROUPED_MASTER,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_GROUPED_MASTER,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_GROUPED_MASTER
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_MULTI_MASTER=168,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_MULTI_MASTER,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_MULTI_MASTER,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_MULTI_MASTER,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_MULTI_MASTER,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_MULTI_MASTER,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_MULTI_MASTER,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_MULTI_MASTER,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_MULTI_MASTER,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_MULTI_MASTER,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_MULTI_MASTER,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_MULTI_MASTER
};

enum {
    INDEPENDENT_NO_SHAPPING_DMX_VALID_MULTI_MASTER_BACKUP=180,
    INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_MULTI_MASTER_BACKUP,
    RX_DISABLED_NO_SHAPPING_DMX_VALID_MULTI_MASTER_BACKUP,
    RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_MULTI_MASTER_BACKUP,
    INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_MULTI_MASTER_BACKUP,
    INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_MULTI_MASTER_BACKUP,
    RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_MULTI_MASTER_BACKUP,
    RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_MULTI_MASTER_BACKUP,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_MULTI_MASTER_BACKUP,
    INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_MULTI_MASTER_BACKUP,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_MULTI_MASTER_BACKUP,
    RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_MULTI_MASTER_BACKUP
};



void process_mode(unsigned char* analog_data, unsigned char* rx_data, int address, unsigned char* output_data, unsigned char* shape,
                  unsigned char status)
{
    int i=0;
    int aux=0;

    switch (status)
    {
        /*OFF MODES*/
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_OFF:
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_OFF:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_OFF:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_OFF:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_OFF:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_OFF:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_OFF:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_OFF:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_OFF:
            /*Min modes if no DMX is present*/
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_MIN:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_MIN:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_MIN:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_MIN:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_MIN:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_MIN:
            /*Backup modes if RX disabled and a valid frame is present*/
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_BACKUP:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_BACKUP:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_BACKUP:
            /*Rx modes if no valid frame is present or RX disabled */
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_RX:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_RX:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_RX:
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_RX:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_RX:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_RX:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_RX:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_RX:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_RX:
                    clear_tx_before(DMX_TX_BUFFER_SIZE, output_data); //Full output off
                    break;
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_OFF:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_OFF:
                    for(i=address; i-address<ANALOG_CHANNELS_SIZE && i<DMX_TX_BUFFER_SIZE; i++) // Analog ch off, rest bypassed
                    {
                        output_data[i]= 0;
                    }
                    copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
                    break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_OFF:
                    for(i=address; i-address<ANALOG_CHANNELS_SIZE && i<DMX_TX_BUFFER_SIZE; i++) // Analog ch off, rest shapped
                    {
                        output_data[i]= 0;
                    }
                    shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
                    break;
                    
        /*ON modes*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_ON:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_ON:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++) 
            {
                output_data[i] = DMX_MAX_VALUE;
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;
            
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_ON:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++) 
            {
                output_data[i] = DMX_MAX_VALUE;
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;
            
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_ON:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_ON:        
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_ON:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_ON:       
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_ON:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_ON:
            for (i = 0; i < DMX_TX_BUFFER_SIZE; i++) 
            {
                output_data[i] = DMX_MAX_VALUE;
            }
            break;
            
        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_ON:
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_ON:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_ON:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++) 
            {
                output_data[i] = DMX_MAX_VALUE;
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

       /*Add modes*/

        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_ADD:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] + shape[analog_data[i - address]]; //Adds channel
                if (aux > DMX_MAX_VALUE)
                {
                    output_data[i] = DMX_MAX_VALUE;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_ADD:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] + analog_data[i - address]; //Adds channel
                if (aux > DMX_MAX_VALUE)
                {
                    output_data[i] = DMX_MAX_VALUE;
                } else
                {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;

        case INDEPENDENT_NO_SHAPPING_DMX_VALID_ADD:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] + analog_data[i - address]; //Adds channel
                if (aux > DMX_MAX_VALUE)
                {
                    output_data[i] = DMX_MAX_VALUE;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_ADD:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] + shape[analog_data[i - address]]; //Adds channel
                if (aux > DMX_MAX_VALUE)
                {
                    output_data[i] = DMX_MAX_VALUE;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_ADD:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] + analog_data[i - address]; //Adds channel
                if (aux > DMX_MAX_VALUE)
                {
                    output_data[i] = DMX_MAX_VALUE;
                } else
                {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_NO_SHAPPING_DMX_VALID_ADD:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] + analog_data[i - address]; //Adds channel
                if (aux > DMX_MAX_VALUE)
                {
                    output_data[i] = DMX_MAX_VALUE;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;
                
        /*Diff1 modes*/

        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_DIFF1:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = shape[analog_data[i - address]] - rx_data[i]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_DIFF1:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address] - rx_data[i]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;

        case INDEPENDENT_NO_SHAPPING_DMX_VALID_DIFF1:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address] - rx_data[i]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_DIFF1:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = shape[analog_data[i - address]] - rx_data[i]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_DIFF1:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address] - rx_data[i]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case RX_DISABLED_NO_SHAPPING_DMX_VALID_DIFF1:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address] - rx_data[i]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
         
        /*Diff2 modes*/
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] - shape[analog_data[i - address]]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] - analog_data[i - address]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;

        case INDEPENDENT_NO_SHAPPING_DMX_VALID_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] - analog_data[i - address]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] - shape[analog_data[i - address]]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] - analog_data[i - address]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case RX_DISABLED_NO_SHAPPING_DMX_VALID_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i] - analog_data[i - address]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_DIFF2:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = DMX_MAX_VALUE - analog_data[i - address]; //Diffs channel
                if (aux < 0) {
                    output_data[i] = 0;
                } else {
                    output_data[i] = (unsigned char) aux;
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF2:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = DMX_MAX_VALUE - shape[analog_data[i - address]]; //Diffs channel
                if (aux < 0)
                {
                    output_data[i] = 0;
                } else
                {
                    output_data[i] = (unsigned char) aux;
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF2:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF2:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++) {
                aux = DMX_MAX_VALUE - analog_data[i - address]; //Diffs channel
                if (aux < 0) {
                    output_data[i] = 0;
                } else {
                    output_data[i] = shape[(unsigned char) aux];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;


            /*Max Modes*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_MAX:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address]; //Diffs channel
                if (aux > rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_NO_SHAPPING_DMX_VALID_MAX:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address]; // max channel
                if (aux > rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;


        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_MAX:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = shape[analog_data[i - address]];
                if (aux > rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_MAX:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = shape[analog_data[i - address]];
                if (aux > rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_MAX:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address];
                if (aux > rx_data[i])
                {
                    output_data[i] = shape[(unsigned char) aux];
                } else
                {
                    output_data[i] = shape[rx_data[i]];
                }
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;

        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_MAX:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address];
                if (aux > rx_data[i])
                {
                    output_data[i] = shape[(unsigned char) aux];
                } else
                {
                    output_data[i] = shape[rx_data[i]];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

            /*Min modes*/
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_MIN:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = shape[analog_data[i - address]];
                if (aux < rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_MIN:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address];
                if (aux < rx_data[i])
                {
                    output_data[i] = shape[(unsigned char) aux];
                } else
                {
                    output_data[i] = shape[rx_data[i]];
                }
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;

        case INDEPENDENT_NO_SHAPPING_DMX_VALID_MIN_MIN:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address]; //Diffs channel
                if (aux < rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_MIN:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = shape[analog_data[i - address]];
                if (aux < rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_MIN:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address];
                if (aux < rx_data[i])
                {
                    output_data[i] = shape[(unsigned char) aux];
                } else
                {
                    output_data[i] = shape[rx_data[i]];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case RX_DISABLED_NO_SHAPPING_DMX_VALID_MIN:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = analog_data[i - address]; // max channel
                if (aux < rx_data[i])
                {
                    output_data[i] = (unsigned char) aux;
                } else
                {
                    output_data[i] = rx_data[i];
                }
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

            /*AVG modes*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                    aux = rx_data[i];
                    output_data[i]=(unsigned char) (aux+analog_data[i-address])/2;
                }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                output_data[i]=(unsigned char) analog_data[i-address]/2;
                }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                    aux = rx_data[i];
                    output_data[i]=(unsigned char) (aux+analog_data[i-address])/2;
                }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = (unsigned char) analog_data[i - address] / 2;
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                    aux = rx_data[i];
                    output_data[i]=(unsigned char) (aux+shape[analog_data[i-address]])/2; //Avg channel
                }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;
        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                    output_data[i]=(unsigned char) shape[analog_data[i-address]]/2; //Avg channel
                }
           copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
           break;
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i];
                output_data[i] = (unsigned char) (aux + shape[analog_data[i - address]]) / 2; //Avg channel
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = (unsigned char) shape[analog_data[i - address]] / 2; //Avg channel
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                    aux = rx_data[i];
                    output_data[i]=shape[(unsigned char) (aux+analog_data[i-address])/2];
                }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
                {
                    output_data[i]=shape[(unsigned char) analog_data[i-address]/2];
                }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                aux = rx_data[i];
                output_data[i] = (unsigned char) (aux + analog_data[i - address]) / 2;
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_AVG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = (unsigned char) analog_data[i - address] / 2;
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;
            
            /*Backup modes*/
            /*If a valid frame is present and RX is enabled, DMX frames are passed by*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_BACKUP:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_BACKUP:
            /*RX modes*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_RX:
        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_RX:
            copy_tx_before(DMX_TX_BUFFER_SIZE, rx_data, output_data);
            break;
            /*If a valid frame is present an RX is enabled, frames are shapped by*/
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_BACKUP:
            /*RX modes*/
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_RX:
            shape_tx_before(DMX_TX_BUFFER_SIZE, rx_data, output_data, shape);
            break;



            /*Analog only*/
            /*RX enabled and valid frame present*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_ANALOG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = analog_data[i - address];
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_ANALOG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = shape[analog_data[i - address]];
            }
            copy_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data);
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_ANALOG:
            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = shape[analog_data[i - address]];
            }
            shape_tx(address, ANALOG_CHANNELS_SIZE, rx_data, output_data, shape);
            break;

            /*RX disabled or invalid*/
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_ANALOG:
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_ANALOG:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_ANALOG:

        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_BACKUP:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_BACKUP:

        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_MAX:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_MAX:

        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_DIFF1:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_DIFF1:

        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_ADD:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_ADD:

            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = analog_data[i - address];
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_ANALOG:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_ANALOG:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_ANALOG:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_ANALOG:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_ANALOG:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_ANALOG:

        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_BACKUP:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_BACKUP:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_BACKUP:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_BACKUP:

        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_MAX:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_MAX:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_MAX:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_MAX:

        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_ADD:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_ADD:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_ADD:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_ADD:

        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF1:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_DIFF1:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF1:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_DIFF1:

            for (i = address; i - address < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = shape[analog_data[i - address]];
            }
            clear_tx(address, ANALOG_CHANNELS_SIZE, output_data);
            break;

            /*Chained modes*/
        case INDEPENDENT_NO_SHAPPING_DMX_VALID_CHAINED:
            for (i = 0; i <= address && i < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = analog_data[i];
            }
            for (++i, aux=0; i < DMX_TX_BUFFER_SIZE && aux  <DMX_TX_BUFFER_SIZE; i++, aux++)
            {
                output_data[i]=rx_data[aux];
            }
            break;

        case INDEPENDENT_ANALOG_SHAPPING_DMX_VALID_CHAINED:
            for (i = 0; i <= address && i < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = shape[analog_data[i]];
            }
            for (++i, aux = 0; i < DMX_TX_BUFFER_SIZE && aux < DMX_TX_BUFFER_SIZE; i++, aux++)
            {
                output_data[i] = rx_data[aux];
            }
            break;

        case INDEPENDENT_GLOBAL_SHAPPING_DMX_VALID_CHAINED:
            for (i = 0; i <= address && i < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE; i++)
            {
                output_data[i] = shape[analog_data[i]];
            }
            for (++i, aux = 0; i < DMX_TX_BUFFER_SIZE && aux < DMX_TX_BUFFER_SIZE; i++, aux++) 
            {
                output_data[i] = shape[rx_data[aux]];
            }
            break;

            /*Analog only copied, RX to 0*/
        case INDEPENDENT_NO_SHAPPING_DMX_DEPRECATED_CHAINED:
        case RX_DISABLED_NO_SHAPPING_DMX_VALID_CHAINED:
        case RX_DISABLED_NO_SHAPPING_DMX_DEPRECATED_CHAINED:
            for (i = 0; i <= address && i < ANALOG_CHANNELS_SIZE; i++)
            {
                output_data[i] = analog_data[i];
            }
            clear_tx_after(i+1, output_data);
            break;

            /*Analog only shapped, RX to 0*/
        case INDEPENDENT_ANALOG_SHAPPING_DMX_DEPRECATED_CHAINED:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_VALID_CHAINED:
        case RX_DISABLED_ANALOG_SHAPPING_DMX_DEPRECATED_CHAINED:
        case INDEPENDENT_GLOBAL_SHAPPING_DMX_DEPRECATED_CHAINED:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_VALID_CHAINED:
        case RX_DISABLED_GLOBAL_SHAPPING_DMX_DEPRECATED_CHAINED:
            for (i = 0; i <= address && i < ANALOG_CHANNELS_SIZE; i++)
            {
                output_data[i] = shape[analog_data[i]];
            }
            clear_tx_after(i+1, output_data);
            break;



    }
}


void clear_tx_before(int end_channel, unsigned char* data_out){
    int aux;
    for (aux=0; aux<end_channel; aux++)
    {
        data_out[aux]=0;
    }
}

/*Cleans upper part of tx buffer
/* needs first channel to clean and data address
 */
void clear_tx_after (int begin_channel, unsigned char* data_out)
{
    int aux;
    for (aux=begin_channel; aux<DMX_TX_BUFFER_SIZE; aux++)
    {
        data_out[aux]=0;
    }
}

void clear_tx (int address, int gap, unsigned char* data_out)
{
    int aux;
    for (aux = 0; aux < address; aux++)
    {
        data_out[aux] = 0;
    }
    for (aux = address+gap; aux < DMX_TX_BUFFER_SIZE; aux++)
    {
        data_out[aux] = 0;
    }
}

void copy_tx_before(int end_channel, unsigned char* data_in, unsigned char* data_out)
{
    int aux;
    for (aux=0; aux<end_channel; aux++)
    {
        data_out[aux]=data_in[aux];
    }
}

void copy_tx_after(int begin_channel, unsigned char* data_in, unsigned char* data_out)
{
    int aux;
    for (aux = begin_channel; aux < DMX_TX_BUFFER_SIZE; aux++) {
        data_out[aux] = data_in[aux];
    }
}

void copy_tx(int address, int gap, unsigned char* data_in, unsigned char* data_out) {
    int aux;
    for (aux = 0; aux < address; aux++) {
        data_out[aux] = data_in[aux];
    }
    for (aux = address + gap; aux < DMX_TX_BUFFER_SIZE; aux++) {
        data_out[aux] = data_in[aux];
    }
}

void shape_tx_before(int end_channel, unsigned char* data_in, unsigned char* data_out, unsigned char* shape)
{
    int aux;
    for (aux=0; aux<end_channel; aux++)
    {
        data_out[aux]=data_in[shape[aux]];
    }
}

void shape_tx_after(int begin_channel, unsigned char* data_in, unsigned char* data_out, unsigned char* shape) {
    int aux;
    for (aux = begin_channel; aux < DMX_TX_BUFFER_SIZE; aux++) {
        data_out[aux] = data_in[shape[aux]];
    }
}

void shape_tx(int address, int gap, unsigned char* data_in, unsigned char* data_out, unsigned char* shape) {
    int aux;
    for (aux = 0; aux < address; aux++) {
        data_out[aux] = data_in[shape[aux]];
    }
    for (aux = address + gap; aux < DMX_TX_BUFFER_SIZE; aux++) {
        data_out[aux] = data_in[shape[aux]];
    }
}

