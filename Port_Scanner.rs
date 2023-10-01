use std::env;
use std::net::{IpAddr, Ipv4Addr, SocketAddr, TcpListener};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 5 {
        println!("Usage: {} -s <start_port> -e <end_port>", args[0]);
        return;
    }

    let start_port = match args[2].parse::<u16>() {
        Ok(port) => port,
        Err(_) => {
            println!("Invalid start port");
            return;
        }
    };

    let end_port = match args[4].parse::<u16>() {
        Ok(port) => port,
        Err(_) => {
            println!("Invalid end port");
            return;
        }
    };

    for port in start_port..=end_port {
        let ip = IpAddr::V4(Ipv4Addr::new(127, 0, 0, 1));
        let socket_addr = SocketAddr::new(ip, port);

        if is_port_open(socket_addr) {
            println!("Port {} is open", port);
        }
    }
}

fn is_port_open(socket_addr: SocketAddr) -> bool {
    if let Ok(listener) = TcpListener::bind(socket_addr) {
        drop(listener);
        true
    } else {
        false
    }
}



// Cargo.toml

// [package]
// name = "port-scanner"
// version = "0.1.0"

// [dependencies]

//Run:
// cargo run -- -s 1 -e 2222
