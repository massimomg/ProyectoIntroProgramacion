#include <iostream>
using namespace std;
//declaracion de estructuras y constantes
using namespace std;
const int no_empleados = 5;
const int no_productos = 20;

struct Producto
{
    string nombre="";
    int disponible=0;
    float precioventa=0;
    string fechaI="";
    string fechaV="";
};

struct Empleado
{
	int cargo=0; //1 si es empleado, 0 si es administrador
	string uname="";
	string psw="";
    int articulosvendidos=0;
    float dinerorecaudado=0;
    Producto productosvendidos[no_productos];
};

void imprimirlista(Producto productos[])
{
    for(int i=0; i<no_productos; i++)
    {
        cout<<"-----------------------------------"<<endl;
        cout<<productos[i].nombre<<endl;
        cout<<productos[i].disponible<<endl;
        cout<<productos[i].precioventa<<endl;
        cout<<productos[i].fechaI<<endl;
        cout<<productos[i].fechaV<<endl;
        cout<<"-----------------------------------"<<endl;
    }
}

int login(Empleado empleados[])
{
    string password;
    string user;
    int limite = 0;
    cout<<"ingrese su usuario"<<endl;
    cin>>user;
    
    for(int i=0;i<no_empleados;i++)
    {
        if(empleados[i].uname==user)
        {
            while(limite<3)
            {
                cout<<"ingrese su contraseña"<<endl;
                cin>>password;
                if(empleados[i].psw==password)
                {
                    //obtener index
                    return i;
                }
                else
                {
                    cout<<"contraseña errada"<<endl;
                    limite++;
                }
            }
            
        }
    }
    if(limite>=3)
    {
        return -1;
    }
}

void imprimirMenuEmpleado()
{
    cout<<"Bienvenido al MENU"<<endl;
    cout<<"(1) Registrar el ingreso de un nuevo producto"<<endl;
    cout<<"(2) Vender un producto"<<endl;
    cout<<"(3) Ver productos en inventario"<<endl;
    cout<<"(0) cerrar"<<endl;
}

void imprimirMenuAdmin()
{
    cout<<"Bienvenido al MENU"<<endl;
    cout<<"(1) Historial de ventas"<<endl;
    cout<<"(2) Historial de ventas por vendedor"<<endl;
    cout<<"(3) Aplicar bonificación al vendedor con más artículos vendidos"<<endl;
    cout<<"(4) Aplicar bonificación al vendedor con el mayor nivel de ventas"<<endl;
    cout<<"(5) registrar un nuevo trabajador al sistema"<<endl;
    cout<<"(0) cerrar"<<endl;
}

void registar(Producto articulos[])
{
    int k=0;
    while(articulos[k].disponible==1)
        {
            k++;
        }
    if(k<no_productos)
    {
        string articulo;
        cout<<"ingrese el nombre del producto en todo en miniscula"<<endl;
        cin>>articulo;
        float precio;
        cout<<"ingrese el precio del producto"<<endl;
        cin>>precio;
        string fechaingreso;
        cout<<"ingrese la fecha"<<endl;
        cin>>fechaingreso;
        articulos[k].nombre=articulo;
        articulos[k].precioventa=precio;
        articulos[k].fechaI=fechaingreso;
        articulos[k].disponible=articulos[k].disponible+1;
    }else{
        cout<<"no hay espacio para más artículos!!"<<endl;
    }
}

void venderproducto(Producto productos[], Empleado empleados[],int index)
{
    string prod;
    cout<<"ingrese el nombre del producto que desea vender"<<endl;
    cin>>prod;
    string fechadeventa;
    Producto vendido;
    for(int i=0; i<no_productos; i++)
    {
	    if(productos[i].nombre==prod)
	    {
		    cout<<"ingrese la fecha actual"<<endl;
    	    cin>>fechadeventa;
    	    productos[i].disponible=0;
    	    productos[i].fechaV=fechadeventa;
    	    empleados[index].articulosvendidos=empleados[index].articulosvendidos+1;
    	    empleados[index].dinerorecaudado=empleados[index].dinerorecaudado + productos[i].precioventa;
            vendido = {productos[i].nombre, 0, productos[i].precioventa, productos[i].fechaI, fechadeventa};
            int k=0;
            while(empleados[index].productosvendidos[k].precioventa!=0)
            {
                k++;
            }
            empleados[index].productosvendidos[k]=vendido;
	    }
    }
}

void verProducto(Producto productos[])
{
    cout<<"ingrese el nombre de el producto"<<endl;
    string Nproducto;
    cin>>Nproducto;
    for(int i=0;i<20;i++)
    {
        if(productos[i].nombre==Nproducto)
        {
            cout<<productos[i].nombre<<endl;
            cout<<productos[i].disponible<<endl;
            cout<<productos[i].precioventa<<endl;
            cout<<productos[i].fechaI<<endl;
            cout<<productos[i].fechaV<<endl;
        }
    }
}

void seleccionEmpleado(Producto productos[], Empleado empleados[], int index)
{
    int sel;
    bool continuar=true;
    while(continuar==true)
    {
        imprimirMenuEmpleado();
        cin>>sel;
        switch(sel)
        {
            case 1:
            registar(productos);
            /*imprimirlista(productos);*/
            break;
            case 2:
            venderproducto(productos, empleados, index);
            /*imprimirlista(productos);*/
            break;
            case 3:
            verProducto(productos);
            break;
            case 0:
            continuar=false;
            break;
        }
    }
}

void historialventas(Empleado empleados[],Producto productos[])
{
    for(int i=0;i<no_empleados;i++)
    {
        for(int j=0; j<no_productos; j++)
        {
            if(empleados[i].productosvendidos[j].nombre!="")
            {
                cout<<"-----------------------------------"<<endl;
                cout<<empleados[i].productosvendidos[j].nombre<<endl;
                cout<<empleados[i].productosvendidos[j].disponible<<endl;
                cout<<empleados[i].productosvendidos[j].precioventa<<endl;
                cout<<empleados[i].productosvendidos[j].fechaI<<endl;
                cout<<empleados[i].productosvendidos[j].fechaV<<endl;
                cout<<"-----------------------------------"<<endl;
            }
        }
    }
    float recaudocomunista=0;
    for(int i=0;i<5;i++)
    {
        recaudocomunista=empleados[i].dinerorecaudado+recaudocomunista;
    }
    cout<<recaudocomunista<<endl;
}

void historialPorVendedor(Empleado empleados[],Producto productos[])
{
    string employee;
    cout<<"escriba el nombre del empleado al cual desea revisar el historial de ventas"<<endl;
    cin>>employee;
    float recaudocomunista = 0;
    for(int i=0; i<no_empleados; i++)
    {
        if(empleados[i].uname==employee)
        {
            for(int j=0; j<no_productos; j++)
            {
                if(empleados[i].productosvendidos[j].nombre!="")
                {
                    cout<<"-----------------------------------"<<endl;
                    cout<<empleados[i].productosvendidos[j].nombre<<endl;
                    cout<<empleados[i].productosvendidos[j].disponible<<endl;
                    cout<<empleados[i].productosvendidos[j].precioventa<<endl;
                    cout<<empleados[i].productosvendidos[j].fechaI<<endl;
                    cout<<empleados[i].productosvendidos[j].fechaV<<endl;
                    cout<<"-----------------------------------"<<endl;
                    recaudocomunista = recaudocomunista + empleados[i].productosvendidos[j].precioventa;
                }
            }
        }
    }
    cout<<recaudocomunista<<endl;
}

Empleado empleadoEstrellaCantidad(Producto productos[], Empleado empleados[])
{
    Empleado estrella;
    int max = 0;
    for(int i=0; i<no_empleados; i++)
    {
        for(int j=0; j<no_productos; j++)
        {
            if(empleados[i].articulosvendidos>=max)
            {
                estrella=empleados[i];
                max=empleados[i].articulosvendidos;
            }
        }
    }
    cout<<"el empleado que más artículos vendió fue "<<estrella.uname<<" vendió: "<<estrella.articulosvendidos<<endl;
    return estrella;
}

Empleado empleadoEstrellaVentas(Producto productos[], Empleado empleados[])
{
    Empleado estrella;
    float max = 0;
    for(int i=0; i<no_empleados; i++)
    {
        for(int j=0; j<no_productos; j++)
        {
            if(empleados[i].dinerorecaudado>=max)
            {
                estrella=empleados[i];
                max=empleados[i].dinerorecaudado;
            }
        }
    }
    cout<<"el empleado que más vendió fue "<<estrella.uname<<" vendió: "<<estrella.articulosvendidos<<endl;
    return estrella;
}

void registrarEmpleado(Empleado empleados[])
{
    int new_cargo;
    string new_uname;
    string new_psw;
    cout<<"Qué nombre de usuario desea? "<<endl;
    cin>>new_uname;
    cout<<"Qué contraseña desea? "<<endl;
    cin>>new_psw;
    cout<<"Qué cargo ejercerá? "<<endl;
    cin>>new_cargo;
    Empleado New = {new_cargo, new_uname, new_psw, 0, 0};
    int k=0;
    while(empleados[k].uname!="")
    {
        k++;
    }
    empleados[k]=New;
}

void seleccionAdmin(Producto productos[], Empleado empleados[], int index)
{
    int sel;
    bool continuar=true;
    while(continuar==true)
    {
        imprimirMenuAdmin();
        cin>>sel;
        switch(sel)
        {
        case 1:
        historialventas(empleados,productos);
        break;
        case 2:
        historialPorVendedor(empleados,productos);
        break;
        case 3:
        empleadoEstrellaCantidad(productos,empleados);
        break;
        case 4:
        empleadoEstrellaVentas(productos,empleados);
        break;
        case 5:
        registrarEmpleado(empleados);
        break;
        case 0:
        continuar = false;
        break;
        }
    }
}

int main(){
    Empleado empleados[no_empleados];
    Producto productos[no_productos];

    empleados[0] = {0, "simonki", "123", 0, 0};
    empleados[1] = {0, "maimonema", "hola", 0, 0};
    empleados[2] = {1, "molasimon", "123", 0, 0};
    empleados[3] = {1, "Carlos", "2040", 0, 0};

    productos[0] = {"panela", 1, 4000, "20/07/2022", ""};
    productos[1] = {"arepas", 1, 10000, "27/08/2022", ""};
    productos[2] = {"huevos", 1, 12000, "20/09/2022", ""};
    productos[3] = {"anchoas", 1, 21000, "25/09/2022", ""};

    int index;

    while(true)
    {
        index=login(empleados);
        if(index==-1)
        {
            cout<<"demasiados intentos"<<endl;
        }else{
            if (empleados[index].cargo==0)
            {
                //menu admin
                //cout<<"qhubopa, cvero admin"<<endl;
                seleccionAdmin(productos,empleados,index);
            }
            if (empleados[index].cargo==1)
            {
                //menu empleado
                //cout<<"qhubopa, plebeyo"<<endl;
                seleccionEmpleado(productos, empleados, index);
            }
        }
    }
}