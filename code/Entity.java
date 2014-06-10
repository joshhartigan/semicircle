package crotchet;

import java.awt.*;
import java.util.ArrayList;

public class Entity {

    public static ArrayList<Entity> entities = new ArrayList<Entity>();

    private int x, y;
    private int width, height;
    private Color color; // will eventually be replaced with sprite

    public Entity() {}

    public Entity(int nx, int ny, int nwidth, int nheight, Color ncolor) {
        x = nx;
        y = ny;
        width = nwidth;
        height = nheight;
        color = ncolor;
    }

    public void draw(Graphics g) {
        g.setColor(color);
        g.fillRect(x, y, width, height);
    }

    public Rectangle getBounds() {
        return new Rectangle(x, y, width, height);
    }

    // set
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    // get
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
}

class Player extends Entity {
    private int x, y;
    private int width, height;
    private Color color;
    private boolean onGround;

    private String direction = "none";

    private int xVel, yVel;

    public Player(int nx, int ny, int nwidth, int nheight, Color ncolor) {
        x = nx;
        y = ny;
        width = nwidth;
        height = nheight;
        color = ncolor;
    }

    public void draw(Graphics g) {
        g.setColor(color);
        g.fillRect(x, y, width, height);
    }

    public void move() {
        setX(getX() + xVel);
        setY(getY() + yVel);
        System.out.println("xVel at " + xVel + ", yVel at " + yVel);
    }

    public Rectangle getBounds() {
        return new Rectangle(x, y, width, height);
    }

    // set
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    public void setOnGround(boolean ground) {
        onGround = ground;
    }

    public void setxVel(int xVel) {
        this.xVel = xVel;
    }
    public void setyVel(int yVel) {
        this.yVel = yVel;
    }

    public void setDirection(String dir) {
        this.direction = dir;
    }

    // get
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
    public boolean getOnGround() {
        return onGround;
    }

    public int getxVel() {
        return xVel;
    }
    public int getyVel() {
        return yVel;
    }

    public String getDirection() {
        return direction;
    }
}

