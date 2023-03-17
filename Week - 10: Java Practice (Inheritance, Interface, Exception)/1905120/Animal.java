public class Animal {
    private String name;
    private int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override public void print(Animal a) {
        System.out.print(a.name + " is a " + a.getClass().getName() + ", aged " + a.age );
    }


}