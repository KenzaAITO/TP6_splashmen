
void actions_do(t_player *p_player, enum action act_id){
    switch (act_id){
    case 0 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits--;
        }else printf("credits nn suffisant!");
        break;
    case 1 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits--;
            if(p_player->x==0){
                p_player->x=MAP_SIZE-1;
            }else{p_player->x--;}
            
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        
        break;
    case 2 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits--;
            if(p_player->x==MAP_SIZE-1){
                p_player->x=0;
            }else{p_player->x++;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;

    case 3 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits--;
            if(p_player->y==0){
                p_player->y=MAP_SIZE-1;
            }else{p_player->y--;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;
    case 4 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits--;
            if(p_player->y==MAP_SIZE-1){
                p_player->y=0;
            }else{p_player->y++;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;
    case 5 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=8;
            int cpt=8;
            while (cpt>0){
                if(p_player->x==0){
                p_player->x=MAP_SIZE-1;
                
            }else{p_player->x--;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
            cpt--;
            } 
        }else printf("credits nn suffisant!");
        
        break;
    case 6 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=8;
            int cpt=8;
            while (cpt>0){
                if(p_player->x==MAP_SIZE-1){
                p_player->x=0;
                
            }else{p_player->x++;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
            cpt--;
            } 
        }else printf("credits nn suffisant!");
        break;
    case 7 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=8;
            int cpt=8;
            while (cpt>0){
                if(p_player->y==0){
                p_player->y=MAP_SIZE-1;
                
            }else{p_player->y--;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
            cpt--;
            } 
        }else printf("credits nn suffisant!");
        break;
    case  8:
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=8;
            int cpt=8;
            while (cpt>0){
                if(p_player->y==MAP_SIZE-1){
                p_player->y=0;
                
            }else{p_player->y++;}
            world_paint_spot(p_player->x, p_player->y, p_player->id);
            cpt--;
            } 
        }else printf("credits nn suffisant!");
        break;
    case  9:
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=2;
            int cpt=8;
            while (cpt>0){
                if(p_player->x==0){
                p_player->x=MAP_SIZE-1;
            }else{p_player->x--;}
            cpt--;
            } 
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;
    case  10:
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=2;
            int cpt=8;
            while (cpt>0){
                if(p_player->x==MAP_SIZE-1){
                p_player->x=0;
            }else{p_player->x++;}
            cpt--;
            } 
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;
    case 11 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=2;
            int cpt=8;
            while (cpt>0){
                if(p_player->y==0){
                p_player->y=MAP_SIZE-1;
            }else{p_player->y--;}
            cpt--;
            } 
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;
    case 12 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=2;
            int cpt=8;
            while (cpt>0){
                if(p_player->y==MAP_SIZE-1){
                p_player->y=0;
            }else{p_player->y++;}
            cpt--;
            } 
            world_paint_spot(p_player->x, p_player->y, p_player->id);
        }else printf("credits nn suffisant!");
        break;
    case 13 :
        p_player->count++;
        if (p_player->credits >0){
            p_player->credits-=8;
            int a=p_player->x;
            int b=p_player->y;
            for (int i=a-1; i<3;i++){
                if(i==MAP_SIZE){
                    i=0;}
                else if(i<0){
                    i=MAP_SIZE-1;
                }
                for(int j=b-1;j<3;j++){
                    if(j==MAP_SIZE){
                        j=0;
                        world_paint_spot(i, j, p_player->id);
                    }else if(j<0){
                        j=MAP_SIZE-1;
                        world_paint_spot(i, j, p_player->id);
                    }else{
                        world_paint_spot(i, j, p_player->id);}
                    
                }
            }
        }else printf("credits nn suffisant!");
        break;
    case 14 :
        if (p_player->credits >0){
            p_player->count++;
            p_player->credits-=9;
            int a=p_player->x;
            int b=p_player->y;
            p_player->count;
            int c= p_player->count + BOMB_COUNTER ;
            while (c!=p_player->count);
            for (int i=a-1; i<3;i++){
                if(i==MAP_SIZE){
                    i=0;}
                else if(i<0){
                    i=MAP_SIZE-1;
                }
                for(int j=b-1;j<3;j++){
                    if(j==MAP_SIZE){
                        j=0;
                        world_paint_spot(i, j, p_player->id);
                    }else if(j<0){
                        j=MAP_SIZE-1;
                        world_paint_spot(i, j, p_player->id);
                    }else{
                        world_paint_spot(i, j, p_player->id);}
                }
            }
        }else printf("credits nn suffisant!");
        break;
    }
}
actions_init()
{
    p_player->count=0;
    p_player->credits=P_CREDITS;

}