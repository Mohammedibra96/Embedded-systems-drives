/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef LIN_CONFIG_H
#define LIN_CONFIG_H



/*OPtions:
 *			LIN_NODE_MODE_MASTER
 *			LIN_NODE_MODE_SLAVE
 * */


#define LIN_NODE_MODE LIN_NODE_MODE_MASTER


#define LIN_SLAVE_ID		0x01


#define CHECK_SUM   CHECK_SUM_ENHANCED

#define MAX_NUM_MESSAGES               16


#define NUM_CNFG_MESSAGES     3

#endif
