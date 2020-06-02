package ntou.cs.java2020.hw3;//00757143楊明哲

import java.util.Iterator;
import java.util.Random;
import java.util.ArrayList;
//如果有些東西看起來不像人寫的是因為我從.class檔反編譯回來的
//我的檔案莫名其妙地消失了 我只救得回來.class檔
//人類看不太懂的地方我已經盡力改掉了
//打了很久的東西直接不見我其實真的心很累
//如果有不符合駱駝式命名的真心希望可以忽略掉 因為我真的寫的時候都有用駱駝式
//所以請高抬貴手 拜託了><
public class Player
{
    public static double MAX_HP;
    public static int DEFAULT_HP;
    public static int DEFAULT_ATK;
    private double hp;
    private ArrayList<ATK> equipment;
    Random random;
    
    public Player() {//什麼都沒有的建構元
        this.equipment = new ArrayList<ATK>();
        this.random = new Random();
        this.hp = Player.DEFAULT_HP;
        this.equipment.add((ATK)new NormalWeapon((double)Player.DEFAULT_ATK, 0.0));
    }
    
    public Player(final double hp) {//有hp的建構元
        this.equipment = new ArrayList<ATK>();
        this.random = new Random();
        this.hp = hp;
        this.equipment.add((ATK)new NormalWeapon((double)Player.DEFAULT_ATK, 0.0));
    }
    
    public Player(final double hp, final ArrayList<ATK> equipment) {//有hp跟裝備的建構元
        this.equipment = new ArrayList<ATK>();
        this.random = new Random();
        this.hp = hp;
        this.equipment = equipment;
    }
    
    public double getHp() {//回傳血量
        return this.hp;
    }
    
    public final void setHp(final double hp) {//設定hp 若負就0
        if (0.0 < hp && hp < Player.MAX_HP) {
            this.hp = hp;
        }
        else {
            this.hp = 0.0;
        }
    }
    
    public ArrayList<ATK> getEquipments() {//回傳裝備
        return this.equipment;
    }
    
    public void setEquipments(final ArrayList<ATK> equipment) {
        this.equipment = equipment;//設定裝備
    }
    
    public double attack(final Player player, final int n) {//攻擊對方 順便辨識是對手還是玩家 1是玩家 2是對手
        final ArrayList<Double> list = new ArrayList<Double>();
        double n2 = 0.0;//原本叫做whoAtk
        final Iterator<ATK> iterator = this.equipment.iterator();
        while (iterator.hasNext()) {//把武器全部加起來
            final double attack = iterator.next().attack();
            n2 += attack;
            list.add(attack);
        }
        System.out.printf("%s攻擊%s %d 點!%n", (n == 1) ? "玩家" : "對手", (n == 1) ? "對手" : "玩家", (int)n2);
        for (int i = 0; i < list.size(); ++i) {
            System.out.printf("[ %s 造成 %d 點的傷害]", this.equipment.get(i).getClass().getSimpleName(), list.get(i).intValue());
        }
        System.out.println();
        System.out.printf("%s的血從 %d 變成 %d !%n", (n == 1) ? "對手" : "玩家", (int)player.getHp(), (player.getHp() - n2 <= 0.0) ? 0 : ((int)(player.getHp() - n2)));
        player.setHp(player.getHp() - n2);
        return player.getHp();
    }
    
    public double defend(final Player player) {//防禦攻擊
        final int n = (this.random.nextInt() % 2 == 0) ? -1 : 1;//治療就-1 反之 1
        if (n == -1) {//原本叫做healHit
            System.out.println("自我療癒了!");
        }
        System.out.printf("玩家攻擊對手 0 點!%n對手的血從 %d 變成 %d%n", (int)player.getHp(), (int)player.getHp());
        System.out.printf("對手攻擊玩家 %d 點!%n", (int)(n * player.getEquipments().get(0).attack() * 0.5));
        System.out.printf("玩家的血從 %d 變成了 %d%n", (int)this.getHp(), (int)(this.getHp() - n * player.getEquipments().get(0).attack() * 0.5));
        this.setHp(this.getHp() - (int)(n * player.getEquipments().get(0).attack() * 0.5));
        return this.getHp();
    }
    
    @Override
    public String toString() {
        return "Player [hp=" + hp + ", equipments=" + equipment + "]";
    }
    
    static {
        Player.MAX_HP = 999.0;
        Player.DEFAULT_HP = 200;
        Player.DEFAULT_ATK = 50;
    }
}