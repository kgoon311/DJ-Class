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
		Attack();
	}
	void Attack()
    {
		if(Input.GetMouseButtonDown(1))
			playerCtrl.ActionAttack(0);
		else if(Input.GetMouseButtonDown(2))
			playerCtrl.ActionAttack(1);
		else if(Input.GetMouseButtonDown(0))
			playerCtrl.ActionAttack(2);
    }
}
