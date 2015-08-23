package crotchet;

import javax.swing.*;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;

@SuppressWarnings("serial")
public class Game extends JFrame {

    public boolean isRunning = false;
    public final int WIDTH = 800, HEIGHT = 600;
    public Insets insets;
    public Keyboard keyboard;
    public Player player;

    public final int GRAVITY = 3;

    public static void main(String[] args) {
        Game game = new Game();
        game.run();
        System.exit(0);
    }

    void run() {
        initialize();

        while (isRunning) {
            long time;
            int fps = 60;

            update();
            draw();

            time = (1000 / fps) - System.currentTimeMillis();
            if (time > 0) {
                try {
                    Thread.sleep(time);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        setVisible(false);
    }

    void initialize() {
        isRunning = true;

        insets = getInsets();

        keyboard = new Keyboard(this);
        buildLevel();

        // create player
        player = new Player(WIDTH / 2, HEIGHT / 2, 20, 40, new Color(166, 132, 38));

        setTitle("crotchet");
        setSize(insets.left + WIDTH + insets.right, insets.top + HEIGHT + insets.bottom);
        setResizable(false);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    void update() {
        // escape -> quit
        if (keyboard.isKeyDown(KeyEvent.VK_ESCAPE)) {
            isRunning = false;
        }
        /*
         * Player Movement
         */
        // d key -> right
        if (keyboard.isKeyDown(KeyEvent.VK_D)) {
            player.setxVel(2);
            player.setDirection("right");
        }
        // a key -> left
        if (keyboard.isKeyDown(KeyEvent.VK_A)) {
            player.setxVel(-2);
            player.setDirection("left");
        }
        // space -> jump
        if (keyboard.isKeyDown(KeyEvent.VK_SPACE)) {
            player.setyVel(-4);
        }
        // stop auto-moving
        // right
        if (player.getDirection().equals("right") && !keyboard.isKeyDown(KeyEvent.VK_D)) {
            player.setxVel(0);
            player.setDirection("none");
        }
        // left
        if (player.getDirection().equals("left") && !keyboard.isKeyDown(KeyEvent.VK_A)) {
            player.setxVel(0);
            player.setDirection("none");
        }
        /*
         * Player Collision
         */
        // fall if in air
        if (!player.getOnGround()) {
            player.setyVel(GRAVITY);
        } else {
            player.setyVel(0);
        }
        // collide with blocks
        for (int ei = 0; ei < Entity.entities.size(); ei++) {
            if (player.getBounds().intersects(Entity.entities.get(ei).getBounds())) {
                player.setOnGround(true);
            }
            // off ground if not on block
            if (player.getOnGround() && !player.getBounds().intersects(Entity.entities.get(ei).getBounds())) {
                player.setOnGround(false);
            }
        }

        player.move();
    }

    void draw() {
        BufferedImage backBuffer;
        backBuffer = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_RGB);

        Graphics g = getGraphics();
        Graphics bbg = backBuffer.getGraphics();

        // draw background
        bbg.setColor(new Color(173, 255, 244));
        bbg.fillRect(0, 0, WIDTH, HEIGHT);

        // draw player
        player.draw(bbg);

        // draw level
        for (int ei = 0; ei < Entity.entities.size(); ei++) {
            Entity.entities.get(ei).draw(bbg);
        }

        // draw image to screen
        g.drawImage(backBuffer, insets.left, insets.top, this);
    }

    void buildLevel() {
        Entity.entities.add(new Entity(100, 560, 600, 20, new Color(67, 196, 67)));
    }
}
