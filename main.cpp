/****************************************************************************
 Ghadhakanka
 Copyright
 ****************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "ALaser.h"
#include "Laser.h"
#include "Spaceship.h"
#include "Star.h"
#include "Aliens.h"
#include "vec2d.h"
#include "Red_Aliens.h"
#include "Yellow_Aliens.h"

void game_over();
void game();
void welcome()
{
	Surface surface(W, H);
	Event event;

	// Aliens images
	Image GA("images/galaxian/Green.gif");
	Rect rectGA = GA.getRect();
	//	rectGA.x = 100;
	rectGA.x = 900;
	rectGA.y = H - 215;
	
	Image RA("images/galaxian/Red.gif");
	Rect rectRA = RA.getRect();
	//	rectRA.x = 250;
	rectRA.x = 1200;
	rectRA.y = H - 215;
	
	Image YA("images/galaxian/Yellow.gif");
	Rect rectYA = YA.getRect();
	//	rectYA.x = 410;
	rectYA.x = 1400;
	rectYA.y = H - 200;

	Image Ship("images/galaxian/Ship.gif");
	Rect rectShip = Ship.getRect();
	//	rectShip.x = 570;
	rectShip.x = 1600;
	rectShip.y = H - 180;

	///////////// Arrow images ////////////
	///////////////////////////////////////

	// right arrow
	Image R_a("images/galaxian/arrowr.png");
	Rect rectR_a = R_a.getRect();
	//	rectGA.x = 200;
	rectR_a.x = 250;
	rectR_a.y = 130;
	
		// right arrow
	// Image R_l("images/galaxian/arrowl.png");
	// Rect rectR_l = R_l.getRect();
	// //	rectGA.x = 200;
	// rectR_l.x = 200;
	// rectR_l.y = 70;
	
		// right arrow
	Image R_u("images/galaxian/arrowu.png");
	Rect rectR_u = R_u.getRect();
	//	rectGA.x = 100;
	rectR_u.x = 250;
	rectR_u.y = 180;
	
		// right arrow
	Image R_d("images/galaxian/arrowd.png");
	Rect rectR_d = R_d.getRect();
	//	rectGA.x = 100;
	rectR_d.x = 250;
	rectR_d.y = 230;
	
	
	
	Font font("fonts/xtrusion.ttf", 55);
	Color c = {255, 255, 0};
	
	Font choice("fonts/dc_s.ttf", 32);
	Color x = {255, 255, 255};

	Font copy("fonts/Copyright.ttf", 30);
	Color r = {0, 153, 153};

	Font fontp("fonts/another.ttf", 30);
	Color p = {255, 255, 0};

	Font dev("fonts/Copyright.ttf", 30);
	Color d = {0, 153, 153};
	
	Font win("fonts/another.ttf", 30);
	Color v = {255, 255, 255};
	
	Image image ("images/galaxian/screen.png");
	Rect rect = image.getRect();

	rect.x = 0;
	rect.y = 0;

      ///////////////////////////////////////
      ////////// Copyright Ghadhakanka //////
      //////////////////////////////////////
      std::string proj_name ("GALAXIAN");
      std::string dev_name ("Sponsor: Dr. Liow");
      std::string right_name ("Copyright: Abdoul Diallo");
      
      char const * arr_project = proj_name.c_str();
      Image project(font.render(arr_project, c));
      Rect rectproj = project.getRect();
      rectproj.x = W/2 - 150;
      rectproj.y = 0;

      char const * arr_dev = dev_name.c_str();
      Image devl(dev.render(arr_dev, d));
      Rect rectdev = devl.getRect();
      rectdev.x = W - 300;
      rectdev.y = H - 60;

      char const * arr_copy = right_name.c_str();
      Image cpy(copy.render(arr_copy, r));
      Rect rectcpy = cpy.getRect();
      rectcpy.x = 5;
      rectcpy.y = H - 60;

      ////////////////////////////////////////
      /////////// Welcome Menu //////////////
      //////////////////////////////////////
      std::string GA_p ("20               40                 80           Player");
      std::string GR_p ("Possible Points");
      std::string GY_p ("Start Game");
      std::string GE_p ("Exit Game");
      std::string GD_p ("Game Description");
      
      char const * arr_GA_p = GA_p.c_str();
      Image point(fontp.render(arr_GA_p, p));
      Rect rectpoint = point.getRect();
      rectpoint.x = 130;
      rectpoint.y = -60;
      //      rectpoint.y = H - 235;

      char const * arr_GR_p = GR_p.c_str();
      Image winp(win.render(arr_GR_p, v));
      Rect rectwin = winp.getRect();
      rectwin.x = -750;
      rectwin.y = H - 275;

      char const * arr_GY_p = GY_p.c_str();
      Image choix(choice.render(arr_GY_p, x));
      Rect rectc = choix.getRect();
      rectc.x = 300;
      rectc.y = 130;

      char const * arr_GE_p = GE_p.c_str();
      Image choie(choice.render(arr_GE_p, x));
      Rect recte = choie.getRect();
      recte.x = 300;
      recte.y = 180;

      char const * arr_GD_p = GD_p.c_str();
      Image choid(choice.render(arr_GD_p, x));
      Rect rectd = choid.getRect();
      rectd.x = 300;
      rectd.y = 230;

	while (1)
	{
	  if (rectGA.x > 100)
	    rectGA.x -= 3;

	  if (rectRA.x > 250)
	    rectRA.x -= 3;

	  if (rectYA.x > 410)
	    rectYA.x -= 3;

	  if (rectShip.x > 570)
	    rectShip.x -= 3;
	  
	  if (rectShip.x <= 570 || rectYA.x <= 410 || rectRA.x <= 250 || rectYA.x <= 100)
	    {
	      if (rectpoint.y < H - 235)
		rectpoint.y +=3;
	      
	      if (rectwin.x < 170)
		rectwin.x +=2;	      
	    }
	  
	  if (event.poll() && event.type() == QUIT) break;
	  KeyPressed keypressed = get_keypressed();
	  
	  if (keypressed[LEFTARROW])
	    {
	      game_over();
	    }
	  else if (keypressed[RIGHTARROW])
	    {
	      game();
	      // break;
	    }
	 else if (keypressed[UPARROW])
	    {
	      break;
	    }
	 else if (keypressed[SDLK_KP_ENTER])
	    {
	      game();
	      break;
	    }
	  
	  surface.lock();
	  surface.put_image(image, rect);
	  surface.put_image(choie, recte);
	  surface.put_image(choid, rectd);
	  surface.put_image(choix, rectc);
	  surface.put_image(R_a, rectR_a);
	  surface.put_image(R_u, rectR_u);
	  surface.put_image(R_d, rectR_d);
	  surface.put_image(winp, rectwin);
	  surface.put_image(point, rectpoint);
	  surface.put_image(cpy, rectcpy);
	  surface.put_image(devl, rectdev);
	  surface.put_image(GA, rectGA);
	  surface.put_image(RA, rectRA);
	  surface.put_image(YA, rectYA);
	  surface.put_image(Ship, rectShip);
	  surface.put_image(project, rectproj);
	  surface.unlock();
	  surface.flip();


	delay(2);
	}
	return;
}

////////////////////////////////////
////////// Game Over ///////////////
////////////////////////////////////
void game_over()
{
  Surface surface(W, H);
  Event event;	
	
	
  Font font("fonts/xtrusion.ttf", 55);
  Color c = {255, 255, 0};

  Font choice("fonts/Follow scratch.ttf", 32);
  Color x = {0, 255, 191};
	
  Image image ("images/galaxian/g3.jpg");
  Rect rect = image.getRect();

  rect.x = 0;
  rect.y = 0;

  ///////////////////////////////////////
  ////////// Copyright Ghadhakanka //////
  //////////////////////////////////////
  std::string proj_name ("GALAXIAN");
  std::string dev_name ("GAME OVER");
      
  char const * arr_project = proj_name.c_str();
  Image project(font.render(arr_project, c));
  Rect rectproj = project.getRect();
  rectproj.x = W/2 - 150;
  rectproj.y = H-50;

  char const * arr_dev = dev_name.c_str();
  Image devl(font.render(arr_dev, c));
  Rect rectdev = devl.getRect();
  rectdev.x = W/2 - 150;
  rectdev.y = 20;

  std::string GA_p ("Player: ");
  std::string GR_p ("Score: ");
  std::string GY_p ("Green Aliens: ");
  std::string GE_p ("Yellow Aliens: ");
  std::string GD_p ("Red Aliens");
      
  char const * arr_GA_p = GA_p.c_str();
  Image point(choice.render(arr_GA_p, x));
  Rect rectpoint = point.getRect();
  rectpoint.x = 30;
  rectpoint.y = 100;
  //      rectpoint.y = H - 235;

  char const * arr_GR_p = GR_p.c_str();
  Image winp(choice.render(arr_GR_p, x));
  Rect rectwin = winp.getRect();
  rectwin.x = 30;
  rectwin.y = 150;

  char const * arr_GY_p = GY_p.c_str();
  Image choix(choice.render(arr_GY_p, x));
  Rect rectc = choix.getRect();
  rectc.x = 30;
  rectc.y = 200;

  char const * arr_GE_p = GE_p.c_str();
  Image choie(choice.render(arr_GE_p, x));
  Rect recte = choie.getRect();
  recte.x = 30;
  recte.y = 250;

  char const * arr_GD_p = GD_p.c_str();
  Image choid(choice.render(arr_GD_p, x));
  Rect rectd = choid.getRect();
  rectd.x = 30;
  rectd.y = 300;
  
  while (1)
    {
      if (event.poll() && event.type() == QUIT) break;
      KeyPressed keypressed = get_keypressed();
	  
      if (keypressed[LEFTARROW])
	{
	  //ship.move_left();
	}
      else if (keypressed[RIGHTARROW])
	{
	  game();
	  break;
	}
      else if (keypressed[UPARROW])
	{
	  break;
	}
      else if (keypressed[SDLK_KP_ENTER])
	{
	  //ship.move_down();
	  game();
	  break;
	}
	  
      surface.lock();
      surface.put_image(image, rect);
      surface.put_image(devl, rectdev);
      surface.put_image(project, rectproj);
      surface.put_image(choid, rectd);
      surface.put_image(choix, rectc);
      surface.put_image(winp, rectwin);
      surface.put_image(point, rectpoint);
      surface.put_image(choie, recte);
      surface.unlock();
      surface.flip();


      delay(2);
    }
  return;
 }


void game()
{
  Surface surface(W, H);
  Event event;
  std::chrono::milliseconds duration(1000);
  // Game start here
  int numStars = 100; // Number of stars to draw
  Spaceship ship (&surface); // Create a ship
  Image background ("images/galaxian/gtwo.jpg");
  Rect ground = background.getRect();
  ground.x = 0;
  ground.y = 0;
	
  Sound sound("sounds/GunSilencer.wav"); // Laser sound
  //Sound space("sounds/spaceshipMoving.wav"); // sound of the ship
  Sound colision("sounds/slap.wav"); // Colision sound
  Music music("sounds/galaxian.ogg"); // Background music
  music.play();
	
  // Number of aliens to draw
  int numGA = 36; //48;
  int numRA = 12;
  int numYA = 4;

  // Total number of lasers
  int numLasers = 100;
  int numALasers = 10;
  int numLife = 1;
	
  // Array pointer of lasers
  Laser * plaser [numLasers];
  ALaser * palaser [numALasers];
  Laser * plife [numLife];
	
  // Pointer array of aliens
  Aliens * pGA [numGA];
  RedAliens * pRA [numRA];
  YellowAliens * pYA [numYA];

  // Boolean variables for next level
  ///////////////////////////////////////
  //////// All Aliens are Dead /////////
  bool GA_dead = 0;
  bool GR_dead = 0;
  bool GY_dead = 0;

  double highscore = (W/2 - 100);
  //std::string gscore("");
  
  Font font("fonts/FreeMonoBold.ttf", 25);
  Color c = {0, 255, 255};

  Font fontlevel("fonts/FreeMonoBold.ttf", 25);
  Color f = {0, 255, 255};

  Font fonth("fonts/FreeMonoBold.ttf", 20);
  Color h = {0, 255, 255};

  Font fontp("fonts/FreeMonoBold.ttf", 20);
  Color p = {0, 255, 255};

   Font nex("fonts/FreeMonoBold.ttf", 20);
  Color n = {0, 255, 255};
  
  // Allocate Memory for Alien Lasers
  for (int i = 0; i < numALasers; i++)
    {
      palaser[i] = new ALaser (&surface);
    }
	
  // Alocate memory for green aliens
  for (int i = 0; i < numGA; ++i)
    {
      pGA[i] = new Aliens (&surface, &ship, palaser);
    }

  // Alocate memory for red aliens
  for (int i = 0; i < numRA; ++i)
    {
      pRA[i] = new RedAliens (&surface, &ship, palaser);
    }

  // Alocate memory for yellow aliens
  for (int i = 0; i < numYA; i++)
    {
      pYA[i] = new YellowAliens (&surface, &ship, palaser);
    }
        
  // Allocate Memory for Spaceship Lasers
  for (int i = 0; i < numLasers; i++)
    {
      plaser[i] = new Laser (&ship);
    }

  // Allocate Memory for Spaceship Life
  for (int i = 0; i < numLife; i++)
    {
      plife[i] = new Laser (&ship);
    }

  // Create a pointer array of stars
  Star * pstar[numStars];

  // Allocate memory for stars
  for (int i = 0; i < numStars; ++i)
    {
      pstar[i] = new Star(&surface);
    }	
  int delaytimer = 0, delay_move = 0, nex_delay = 0,
    death_delay = 0, alien_delay = 0, gameoverdelay = 0;

  bool alien_is_hit = false;
  
  // Moving to next levels
  bool  nextLevel = false, mesg = false, print = false;

  //Update the number of aliens per row
  bool alien_is_dead = false;
  std::string next;
	
  // Dead alien coordonates
  int x = 0, y = 0, ship_bullet_speed = 80;

  int RATE = 1000 / 30;

  int caller = 1;
  while (1)
    {
      ship.back_to_life(); // getting the ship back to life
      // ship score
      // std::cout << ship.total_score() << "\n";
      int start_time = getTicks();
	  
      // Check user inputs
      if (event.poll() && event.type() == QUIT)
	{
	  welcome();
	  break;
	}

      if (ship.life() == 0)
	gameoverdelay++;

      if(gameoverdelay > 400)
	{
	  game_over();
	  break;
	}

      KeyPressed keypressed = get_keypressed();
	  
      delaytimer++; // Increment delay
      delay_move++;
	  
      // randomly pick an alive alien
	  
      if(ship.alive())
	{
	  if (keypressed[LEFTARROW])
	    {
	      ship.move_left();
	    }
	  if (keypressed[RIGHTARROW])
	    {
	      ship.move_right();
	    }
	  if (ship.level() > 1)
	    {
	      if (keypressed[UPARROW])
		{
		  ship.move_up();
		}
	      if (keypressed[DOWNARROW])
		{
		  ship.move_down();
		}
	    }
	  // Simulate firing for the ship
	  if (keypressed[SPACE])
	    {
	      for (int i = 0; i < numLasers; ++i)
		{
		  if (plaser[i]->ready() && delaytimer > ship_bullet_speed)
		    {
		      sound.play();
		      plaser[i] -> shoot();
		      delaytimer = 0;
		      break;
		    }
		}
	    }
	}
      // Simulate moving lasers from bottom to top
      for (int i = 0; i < numLasers; ++i)
	{
	  plaser[i]-> run();
	}


      for (int i = 0; i < numALasers; ++i)
	{
	  palaser[i]-> run();
	}
		 
      // Moving the stars from top to bottom to
      // simulate the ship movement
      for (int i = 0; i < numStars; ++i)
	{
	  pstar[i]->run();
	}
      ////////////////////////////////////
      //////////// Aliens Part ///////////
      for (int i = 0; i < numGA; ++i)
	{
	  pGA[i]->run();
	}

      for (int i = 0; i < numRA; ++i)
	{
	  pRA[i]->run();
	}

      for (int i = 0; i < numYA; i++)
	{
	  pYA[i]->run();
	}
      //////////////////////////////////////////////
      /////////// Compute Collisions ///////////
      //////// Perform collision resolution ////////

      // When ship collide with green_aliens
      for (int i = 0; i < numGA; i++)
	{
	  // If both alien i and ship are alive
	  if (ship.alive() && pGA[i]->alive())
	    {
	      if ((pGA[i]->get_y() <=  ship.get_y()
		   && pGA[i]->get_y() + pGA[i]->get_h() >= ship.get_y()
		   ||
		       
		   pGA[i]->get_y() <=  ship.get_y() + ship.get_h()
		   && pGA[i]->get_y() + pGA[i]->get_h() >= ship.get_y()
		   + ship.get_h()) &&
			      
		  (pGA[i]->get_x() <=  ship.get_x()
		   && pGA[i]->get_x() + pGA[i]->get_w() >= ship.get_x()
		   ||
		       
		   pGA[i]->get_x() <=  ship.get_x() + ship.get_w()
		   && pGA[i]->get_x() + pGA[i]->get_w() >= ship.get_x()
		   + ship.get_w()))
		{
		  death_delay++;
		    if (death_delay > 100)
		    {
		       ship.die();
		       ship.decrease_life();
		       death_delay = 0;
		       break;
		    }
		}
	    }
	}
      
      // When ship collide with red_aliens
      for (int i = 0; i < numRA; i++)
	{
	  // If both alien i and ship are alive
	  if (ship.alive() &&  pRA[i]->alive())
	    {
	      if (( pRA[i]->get_y() <=  ship.get_y()
		    &&  pRA[i]->get_y() +  pRA[i]->get_h() >= ship.get_y()
		    ||
		       
		    pRA[i]->get_y() <=  ship.get_y() + ship.get_h()
		    &&  pRA[i]->get_y() +  pRA[i]->get_h() >= ship.get_y()
		    + ship.get_h()) &&
			      
		  ( pRA[i]->get_x() <=  ship.get_x()
		    &&  pRA[i]->get_x() +  pRA[i]->get_w() >= ship.get_x()
		    ||
		       
		    pRA[i]->get_x() <=  ship.get_x() + ship.get_w()
		    &&  pRA[i]->get_x() +  pRA[i]->get_w() >= ship.get_x()
		    + ship.get_w()))
		{
		  death_delay++;
		  if (death_delay > 100)
		    {
		      ship.die();
		      ship.decrease_life();
		      death_delay = 0;
		      break;
		    }
		}
	    }
	}

      // // When ship collide with yellow_aliens
      for (int i = 0; i < numYA; i++)
	{
	  // If both alien i and ship are alive
	  if (ship.alive() &&  pYA[i]->alive())
	    {
	      if ((pYA[i]->get_y() <=  ship.get_y()
		   && pYA[i]->get_y() + pYA[i]->get_h() >= ship.get_y()
		   ||
		       
		   pYA[i]->get_y() <=  ship.get_y() + ship.get_h()
		   && pYA[i]->get_y() + pYA[i]->get_h() >= ship.get_y()
		   + ship.get_h()) &&
			      
		  (pYA[i]->get_x() <=  ship.get_x()
		   && pYA[i]->get_x() + pYA[i]->get_w() >= ship.get_x()
		   ||
		       
		   pYA[i]->get_x() <=  ship.get_x() + ship.get_w()
		   && pYA[i]->get_x() + pYA[i]->get_w() >= ship.get_x()
		   + ship.get_w()))
		{
		  death_delay++;
		    if (death_delay > 100)
		    {
		       ship.die();
		       ship.decrease_life();
		       death_delay = 0;
		       break;
		    }
		}
	    }
	}

      // When ship collide with an alien laser
      for (int j = 0; j < numALasers; j++)
	{
	  //if both alien i and laser j are alive
	  if(ship.alive() && palaser[j]->alive())
	    {
	      if ((ship.get_y() <=  palaser[j]->get_y()
		   && ship.get_y() + ship.get_h() >= palaser[j]->get_y()
		   ||
		       
		   ship.get_y() <=  palaser[j]->get_y() + palaser[j]->get_h()
		   && ship.get_y() + ship.get_h() >= palaser[j]->get_y()
		   + palaser[j]->get_h()) &&
			      
		  (ship.get_x() <=  palaser[j]->get_x()
		   && ship.get_x() + ship.get_w() >= palaser[j]->get_x()
		   ||
		       
		   ship.get_x() <=  palaser[j]->get_x() + palaser[j]->get_w()
		   && ship.get_x() + ship.get_w() >= palaser[j]->get_x()
		   + palaser[j]->get_w()))
		{
		  death_delay++;
		    if (death_delay > 100)
		    {
		      //colision.play();
		      alien_is_hit = true;
			       
		      // Getting coordinates of the dead alien
		      x = ship.get_x();
		      y = ship.get_y();

		      // Killing both laser and the alien
		      palaser[j]->die();
		      ship.die();
		      ship.decrease_life();
		      death_delay = 0;
		      break;
		    }
		}
	    }
	}
	     
      // When green_aliens collide with a ship laser
      for (int i = 0; i < numGA; i++)
	{
	  for (int j = 0; j < numLasers; j++)
	    {
	      //if both alien i and laser j are alive
	      if(pGA[i]->alive() && plaser[j]->alive())
		{
		  if ((pGA[i]->get_y() <=  plaser[j]->get_y()
		       && pGA[i]->get_y() + pGA[i]->get_h() >= plaser[j]->get_y()
		       ||
		       
		       pGA[i]->get_y() <=  plaser[j]->get_y() + plaser[j]->get_h()
		       && pGA[i]->get_y() + pGA[i]->get_h() >= plaser[j]->get_y()
		       + plaser[j]->get_h()) &&
			      
		      (pGA[i]->get_x() <=  plaser[j]->get_x()
		       && pGA[i]->get_x() + pGA[i]->get_w() >= plaser[j]->get_x()
		       ||
		       
		       pGA[i]->get_x() <=  plaser[j]->get_x() + plaser[j]->get_w()
		       && pGA[i]->get_x() + pGA[i]->get_w() >= plaser[j]->get_x()
		       + plaser[j]->get_w()))
		    {
		      //colision.play();
		      alien_is_hit = true;
			       
		      // Getting coordinates of the dead alien
		      x = pGA[i]->get_x();
		      y = pGA[i]->get_y();

		      // Killing both laser and the alien
		      pGA[i]->die();
		      plaser[j]->die();

		      // Incrementing the score of the ship
		      ship.score(1);
		    }
		}
	    }
	}

      // When red_aliens collide with a ship laser
      for (int i = 0; i < numRA; i++)
	{
	  for (int j = 0; j < numLasers; j++)
	    {
	      //if both alien i and laser j are alive
	      if( pRA[i]->alive() && plaser[j]->alive())
		{
		  if (( pRA[i]->get_y() <=  plaser[j]->get_y()
			&&  pRA[i]->get_y() +  pRA[i]->get_h() >= plaser[j]->get_y()
			||
		       
			pRA[i]->get_y() <=  plaser[j]->get_y() + plaser[j]->get_h()
			&&  pRA[i]->get_y() +  pRA[i]->get_h() >= plaser[j]->get_y()
			+ plaser[j]->get_h()) &&
			      
		      ( pRA[i]->get_x() <=  plaser[j]->get_x()
			&&  pRA[i]->get_x() +  pRA[i]->get_w() >= plaser[j]->get_x()
			||
		       
			pRA[i]->get_x() <=  plaser[j]->get_x() + plaser[j]->get_w()
			&&  pRA[i]->get_x() +  pRA[i]->get_w() >= plaser[j]->get_x()
			+ plaser[j]->get_w()))
		    {
		      //colision.play();
		      alien_is_hit = true;
			       
		      // Getting coordinates of the dead alien
		      x =  pRA[i]->get_x();
		      y =  pRA[i]->get_y();

		      // Killing both laser and the alien
		      pRA[i]->die();
		      plaser[j]->die();

		      // Incrementing the score of the ship
		      ship.score(2);
		    }
		}
	    }
	}
	     
      // When yellow_aliens collide with a ship laser
      for (int i = 0; i < numYA; i++)
	{
	  for (int j = 0; j < numLasers; j++)
	    {
	      //if both alien i and laser j are alive
	      if(pYA[i]->alive() && plaser[j]->alive())
		{
		  if ((pYA[i]->get_y() <=  plaser[j]->get_y()
		       && pYA[i]->get_y() + pYA[i]->get_h() >= plaser[j]->get_y()
		       ||
		       
		       pYA[i]->get_y() <=  plaser[j]->get_y() + plaser[j]->get_h()
		       && pYA[i]->get_y() + pYA[i]->get_h() >= plaser[j]->get_y()
		       + plaser[j]->get_h()) &&
			      
		      (pYA[i]->get_x() <=  plaser[j]->get_x()
		       && pYA[i]->get_x() + pYA[i]->get_w() >= plaser[j]->get_x()
		       ||
		       
		       pYA[i]->get_x() <=  plaser[j]->get_x() + plaser[j]->get_w()
		       && pYA[i]->get_x() + pYA[i]->get_w() >= plaser[j]->get_x()
		       + plaser[j]->get_w()))
		    {
		      //colision.play();
		      alien_is_hit = true;
			       
		      // Getting coordinates of the dead alien
		      x = pYA[i]->get_x();
		      y = pYA[i]->get_y();

		      // Killing both laser and the alien
		      pYA[i]->die();
		      plaser[j]->die();

		      // Incrementing the score of the ship
		      ship.score(3);
		    }
		}
	    }
	}

      ////////////////////////////////////////////////
      ///////////// NEXT LEVEL CONDITIONS ///////////
      //////////////////////////////////////////////
      for (int i = 0; i < numGA; i++)
	{
	  if(pGA[i]->is_dead())
	    {
	      pGA[i]->dead();
	    }
	}

      // If all green aliens are dead
      if (pGA[0]->deadNumber() == numGA)
	{
	  GA_dead = 1;
	}
	   
      for (int i = 0; i < numRA; i++)
	{
	  if(pRA[i]->is_dead())
	    {
	      pRA[i]->dead();
	    }
	}

      // If all red aliens are dead
      if (pRA[0]->deadNumber() == numRA)
	{
	  GR_dead = 1;
	}
	  
      // If all yellow aliens are dead
      for (int i = 0; i < numYA; i++)
	{
	  if(pYA[i]->is_dead())
	    {
	      pYA[i]->dead();
	    }
	}
	  
      // If all red aliens are dead
      if (pYA[0]->deadNumber() == numYA)
	{
	  GY_dead = 1;
	}
	  
      ////////////////////////////////////////////////
      ///// IF NEXT LEVEL CONDITIONS ARE MET /////////
      ///////////////////////////////////////////////
      
      // If all aliens are dead
      if (GR_dead && GA_dead && GY_dead)
	alien_delay++; // Increment delay timer

      // If aliens are dead 400 iterations ago
      if (alien_delay > 700)
	{
	  nextLevel = true;
	  nex_delay++;

	  if (mesg)
	    {
	      //nextLevel = false;
	      for (int i = 0; i < numGA; ++i)
		{
		  pGA[i] -> back_to_life();
		}
		  
	      for (int i = 0; i < numRA; ++i)
		{
		  pRA[i] -> back_to_life();
		}
	  
	      for (int i = 0; i < numYA; i++)
		{
		  pYA[i] -> back_to_life();
		}
	  
	      ship.increase_level();
	      ship_bullet_speed -= 10; //increase the speed of bullets
	      GA_dead = 0;
	      GR_dead = 0;
	      GY_dead = 0;

	      alien_delay = 0;
	    }
     	  nextLevel = false;
      	}
      
      // Drawing
      surface.lock();
      surface.fill(BLACK);
      
      // Loop that simulate the space
      for (int i = 0; i < numStars; ++i)
	{
	  pstar[i]->draw();
	}
		 
      // surface.put_rect (laserX, laserY, 4, 10, 160, 4, 69);
      for (int i = 0; i < numLasers; ++i)
	{
	  plaser[i]-> draw();
	}

       // Simulate spaceship life
      for (int i = 0; i < numLife; ++i)
	{
	  plife[i]-> draw_life();
	}
	  
      for (int i = 0; i < numALasers; ++i)
	{
	  palaser[i]-> draw();
	}

      for (int i = 0; i < numGA; ++i)
	{
	  pGA[i]->draw();
	}

      for (int i = 0; i < numRA; ++i)
	{
	  pRA[i]->draw();
	}

      for (int i = 0; i < numYA; i++)
	{
	  pYA[i]->draw();
	}
      
      ///////////////////////////////////////
      ////////// Spaceship Score ///////////
      /////////////////////////////////////
      std::string gscore ("Score: " + std::to_string(ship.total_score()));
      char const * arr_score = gscore.c_str();
      Image score(font.render(arr_score, c));
      Rect rect = score.getRect();
      rect.x = 5;
      rect.y = H-35;

      ///////////////////////////////////////
      ////////// Spaceship Level ///////////
      /////////////////////////////////////
      std::string glevel ("Level: " + std::to_string(ship.level()));
      char const * arr_level = glevel.c_str();
      Image level(fontlevel.render(arr_level, c));
      Rect rectl = level.getRect();
      rectl.x = W- 140;
      rectl.y = H-35;

      ///////////////////////////////////////
      ////////// Player Name ///////////
      /////////////////////////////////////
      std::string playername ("Player Name: ");
      char const * arr_player = playername.c_str();
      Image player(fontp.render(arr_player, p));
      Rect rectp = player.getRect();
      rectp.x = 1;
      rectp.y = 0;

      ///////////////////////////////////////
      ////////// Highest Score ///////////
      /////////////////////////////////////
      std::string hscore ("Highest Score: " + std::to_string(5432));
      char const * arr_hscore = hscore.c_str();
      Image hscoreimage(fonth.render(arr_hscore, h));
      Rect recth = hscoreimage.getRect();
      recth.x = W- 260;
      recth.y = 0;

      ///////////////////////////////////////
      ////////// Next Leve Message //////////
      //////////////////////////////////////
      if (ship.life() == 0)
	next = ("Total Lives: " + std::to_string(0));
      else
        next = ("Total Lives: ");
      char const * arr_next = next.c_str();
      Image nextim(nex.render(arr_next, n));
      Rect rectn = nextim.getRect();
      rectn.x = 400;
      rectn.y = H-35;

      
      
      //drawing a dead alien image
      if(alien_is_hit)
	{
	  //dead_alien.draw_dead(x, y);
	}
	  
      // Putting the ship in space
      ship.draw();
      surface.put_image(player, rectp);
      surface.put_image(hscoreimage, recth);
      surface.put_image(level, rectl);
      surface.put_image(nextim, rectn);
      if (nextLevel)
      	surface.put_image(nextim, rectn);

      // If next level message is printed for 400 iterations
      if (nex_delay > 400)
      	{
      	  mesg = true;
      	  nex_delay = 0;
      	}
      
      surface.put_image(score, rect);
      surface.unlock();
      surface.flip();

      int end_time = getTicks();
      int dt = end_time - start_time ;
	  
      // if (RATE > dt)
	delay(2);
	  
    } // END OF WHILE LOOP

  //  Dealocate memory for stars
  for (int i = 0; i < numStars; ++i)
    {
      delete pstar[i];
    }

  //  Dealocate memory for lasers
  for (int i = 0; i < numLasers; ++i)
    {
      delete plaser[i];
    }
  
  // Simulate spaceship life
  for (int i = 0; i < numLife; ++i)
    {
      delete plife[i];
    }

  for (int i = 0; i < numALasers; ++i)
    {
      delete palaser[i];
    }

  // Dealocate memory for aliens
  for (int i = 0; i < numGA; ++i)
    {
      delete pGA[i];
    }

  for (int i = 0; i < numRA; ++i)
    {
      delete  pRA[i];
    }

  for (int i = 0; i < numYA; ++i)
    {
      delete pYA[i];
    }

}

int main(int argc, char* argv[])
{
  srand((unsigned int) time(NULL));
  int choix = 0;
  //Surface surface(W, H); // Create surface of width W and height H for drawing
  //Event event; // Create an Event
  switch (choix)
    {
    case 0:
      {
	welcome();
	choix = 1;
      }
      break;

    case 1:
      {

      }
      break;
    }
      
  
  return 0;
}
