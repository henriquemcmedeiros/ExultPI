#include "header.h"


void sons(audio* ptra) {

	// ------ Trilha sonora ------
	ptra->sounds[0] = NULL;
	ptra->inst[0] = NULL;

	ptra->sounds[0] = al_load_sample("Audios/trilha sonora/trilha-sonora.wav"); //carrega qual arquivo vai tocar
	ptra->inst[0] = al_create_sample_instance(ptra->sounds[0]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[0], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_playmode(ptra->inst[0], ALLEGRO_PLAYMODE_LOOP); //coloca a soundtrack em loop
	al_set_sample_instance_gain(ptra->inst[0], 0.25); // VOLUME trilha sonora

	// ------ Porta ------

	ptra->sounds[1] = NULL;
	ptra->inst[1] = NULL;

	ptra->sounds[1] = al_load_sample("Audios/porta/abrindo.wav"); //carrega qual arquivo vai tocar
	ptra->inst[1] = al_create_sample_instance(ptra->sounds[1]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[1], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_gain(ptra->inst[1], 0.25); // VOLUME trilha sonora
	
	// ------ Vitoria ------

	ptra->sounds[2] = NULL;
	ptra->inst[2] = NULL;

	ptra->sounds[2] = al_load_sample("Audios/vitoria/vitoria.wav"); //carrega qual arquivo vai tocar
	ptra->inst[2] = al_create_sample_instance(ptra->sounds[2]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[2], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_gain(ptra->inst[2], 0.25); // VOLUME trilha sonora

	// ------ Derrota ------

	ptra->sounds[3] = NULL;
	ptra->inst[3] = NULL;

	ptra->sounds[3] = al_load_sample("Audios/gritos/morrendo.wav"); //carrega qual arquivo vai tocar
	ptra->inst[3] = al_create_sample_instance(ptra->sounds[3]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[3], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_gain(ptra->inst[3], 0.25); // VOLUME trilha sonora

	// ------ Dialogo ------

	ptra->sounds[4] = NULL;
	ptra->inst[4] = NULL;

	ptra->sounds[4] = al_load_sample("Audios/dialogo/skip.wav"); //carrega qual arquivo vai tocar
	ptra->inst[4] = al_create_sample_instance(ptra->sounds[4]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[4], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_gain(ptra->inst[4], 0.25); // VOLUME trilha sonora

	// ------ Dano ------

	ptra->sounds[5] = NULL;
	ptra->inst[5]  = NULL;

	ptra->sounds[5] = al_load_sample("Audios/dano/hit.wav"); //carrega qual arquivo vai tocar
	ptra->inst[5] = al_create_sample_instance(ptra->sounds[5]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[5], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_gain(ptra->inst[5], 0.25); // VOLUME trilha sonora

	// ------ MiniGame ------

	/*ALLEGRO_SAMPLE* porta = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_porta = NULL;

	porta = al_load_sample("Audios/Porta/abrindo.wav"); //carrega qual arquivo vai tocar
	inst_porta = al_create_sample_instance(porta); //instancia ele
	al_attach_sample_instance_to_mixer(inst_porta, al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_gain(inst_porta, 0.25); // VOLUME trilha sonora
	*/
	
	// ------ Tema Boss ------

	ptra->sounds[7] = NULL;
	ptra->inst[7] = NULL;

	ptra->sounds[7] = al_load_sample("Audios/boss/ticking.wav"); //carrega qual arquivo vai tocar
	ptra->inst[7] = al_create_sample_instance(ptra->sounds[7]); //instancia ele
	al_attach_sample_instance_to_mixer(ptra->inst[7], al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_playmode(ptra->inst[7], ALLEGRO_PLAYMODE_LOOP); //coloca a soundtrack em loop
	al_set_sample_instance_gain(ptra->inst[7], 0.25); // VOLUME trilha sonora

}

void destroyAudios(audio* ptra) {
	// ------ Trilha sonora ------
	al_destroy_sample(ptra->sounds[0]);
	al_destroy_sample_instance(ptra->inst[0]);

	// ------ Porta ------
	al_destroy_sample(ptra->sounds[1]);
	al_destroy_sample_instance(ptra->inst[1]);
	// ------ Vitoria ------
	al_destroy_sample(ptra->sounds[2]);
	al_destroy_sample_instance(ptra->inst[2]);

	// ------ Derrota ------
	al_destroy_sample(ptra->sounds[3]);
	al_destroy_sample_instance(ptra->inst[3]);

	// ------ Dialogo ------
	al_destroy_sample(ptra->sounds[4]);
	al_destroy_sample_instance(ptra->inst[4]);

	// ------ Dano ------
	al_destroy_sample(ptra->sounds[5]);
	al_destroy_sample_instance(ptra->inst[5]);

	// ------ MiniGame ------
	//al_destroy_sample(ptra->sounds[6]);
	//al_destroy_sample_instance(ptra->inst[6]);

	// ------ Tema Boss ------
	al_destroy_sample(ptra->sounds[7]);
	al_destroy_sample_instance(ptra->inst[7]);
}