#pragma once

#define TURNOBLANCAS 0
#define TURNONEGRAS 1

	class Game
	{
	protected:

		bool turnoJugador = TURNOBLANCAS;

	public:

		//Posible idea 
		void changeturno() {
			turnoJugador = TURNOBLANCAS;
		}

		bool getturno() {
			return turnoJugador;
		}

		//A�adido nuevo
		/*
		bool definirturno() {

			if (getturno()) {
				turnoJugador = TURNOBLANCAS;
			}
			else
				turnoJugador = TURNONEGRAS;

			return turnoJugador;
		}

		*/

	};

