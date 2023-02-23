#include <stdlib.h>
#include <stdio.h>

#include "world.h"
#include "param.h"
#include "player.h"
#include "actions.h"




/* !!!!!!!!!!!!!!!! MAP !!!!!!!!!!!!!!!!!!!!! */
uint8_t mapmem[MAP_SIZE * MAP_SIZE] = {0};

/*  PLAYERS */
t_player* players[MAX_PLAYERS] = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_create_players()
{
    int i = 0;

    for (i = 0; i < MAX_PLAYERS; i++)
    {
        players[i] = (t_player*)malloc(sizeof(t_player));
        player_init(players[i], i);
        world_paint_spot(players[i]->x, players[i]->y, players[i]->id);
    }
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
//void world_do_player_action(t_player *p_player)
//{
//}
void world_do_player_action(t_player *p_player)
{
    // Get the player's next action from the play_actions array
 //   char next_action = play_actions[p_player->action];

    // Update the player's position based on the action
   // int new_x = p_player->x;
  //  int new_y = p_player->y;

    // Color the new spot with the player's ID
   // world_paint_spot(new_x, new_y, p_player->id);

    // Update the player's position and action index
   // p_player->x = new_x;
   // p_player->y = new_y;
   // p_player->action++;
}


/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_paint_spot(uint32_t x, uint32_t y, uint32_t num)
{  
    uint32_t pos = y * MAP_SIZE + x;
    mapmem[pos] = num;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_get_winner(t_player* p_player)
{
    int i, j;
    int num_colored_spots[4] = {0};
    int max_spots = 0;
    int max_player = -1;
    
    // Compte le nb de case chaque joeur à colorié     
    for (i = 0; i < MAP_SIZE; i++) 
    {
        for (j = 0; j < MAP_SIZE; j++) 
        {
            int player_id = mapmem[i * MAP_SIZE + j];
            if (player_id >= 0 && player_id < 4) 
            {
                num_colored_spots[player_id]++;
            }
        }
    }
    
    // determiner quel joueur à le plus de case colore dans le jeu     
    for (i = 0; i < MAX_PLAYERS; i++) 
    {
        if (num_colored_spots[i] > max_spots)
        {
            max_spots = num_colored_spots[i];
            max_player = i;
        }
    }
    
    // gagnant   
    if (max_player >= 0 && max_spots > 0) 
    {
        printf("Player %d wins with %d colored spots!\n", max_player, max_spots);
    }
    else
    {
        printf("No winner.\n");//a forcement un vainqueur    
    }
}
