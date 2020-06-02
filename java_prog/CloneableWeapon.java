package ntou.cs.java2020.hw2;//00757143 楊明哲

import java.security.SecureRandom;

public class CloneableWeapon extends Weapon{
    public CloneableWeapon(){
        super(generateRandomOffense());//Calls Weapon's Constructor
    }
    public CloneableWeapon(CloneableWeapon Weapon){
        super(Weapon.getOffense());//Calls Weapon's Constructor
    }
    private static int generateRandomOffense(){
        SecureRandom random = new SecureRandom();
        return (int)(random.nextDouble()*100000000+100000000);//Create a random int       
    }
}