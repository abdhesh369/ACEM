istream& operator>>(istream &in, complex &c) {
    cout << "Enter real part: ";
    in >> c.real;

    cout << "Enter imaginary part: ";
    in >> c.img;

    return in;
}
