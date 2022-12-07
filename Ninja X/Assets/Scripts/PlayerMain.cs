using UnityEngine;
using System.Collections;

public class PlayerMain : MonoBehaviour 
{

	PlayerController 	playerCtrl;

	void Awake () 
	{
		playerCtrl = GetComponent<PlayerController>();
	}

	void Update () 
	{
		if (!playerCtrl.activeSts) 
		{
			return;
		}

		float joyMv = Input.GetAxis ("Horizontal");
		playerCtrl.ActionMove (joyMv);

		if (Input.GetButtonDown ("Jump")) 
		{
			playerCtrl.ActionJump ();
		}
	}

}
