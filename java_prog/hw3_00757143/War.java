package ntou.cs.java2020.hw3;//00757143 楊明哲
import java.util.Random;
import java.util.Scanner;
import ntou.cs.java2020.hw3.NormalWeapon;

import java.util.ArrayList;

public class War {
	public static int ATTACK = 1;
	public static int DEFEND = 2;
	public static int END = 3;

	private Player npc;
	private Player player;
	private Random random;
	private Scanner input;
	public War() {
		random = new Random();
		input = new Scanner(System.in);
		init();
	}

	private void init() {
		int temp1,temp2;//建構所有hp 武器
		ArrayList<ATK> equipment = new ArrayList<ATK>();
		equipment.add((ATK)new NormalWeapon(random.nextInt(40)+20,0));
		equipment.add((ATK)new DoubleWeapon(random.nextInt(35)+25,0));
		temp1=random.nextInt(30)+30;
		equipment.add((ATK)new PowerWeapon(temp1,0));
		temp2=random.nextInt(50)+50;
		equipment.add((ATK)new Pet(temp2));
		player=new Player(random.nextInt(50)+150,equipment);
		npc=new Player(1000-player.getHp());
		System.out.println("您的初始設定：");
		System.out.printf("玩家HP：%d，配戴一般武器攻擊力：%d、加倍武器攻擊力：%d、強力武器攻擊力：%d，Pet攻擊力： %d%n%n",(int)player.getHp(),(int)player.getEquipments().get(0).attack(),(int)player.getEquipments().get(1).attack(),temp1,(int)temp2);
	}

	public void battle() {
		int cmdNum;//互相打
		while(true){
			System.out.printf("請選擇: 1.攻擊 2.防禦 3.結束: ");
			cmdNum=input.nextInt();
			if (cmdNum==3)break;
			else if (cmdNum==1){//attack會回傳目標血量  如果是0就代表擊倒
				if(player.attack(npc,1)==0?true:false){
					System.out.println("擊倒了對手!");
					break;
				}
				else if(npc.attack(player,2)==0?true:false){
					System.out.println("玩家被擊倒了!");
					break;
				}
			}
			else{//defend會回傳自己的血量
				if(player.defend(npc)==0?true:false){
					System.out.println("玩家被擊倒了!");
					break;
				}
			}
		}
	}
}
