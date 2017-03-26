import React, { Component } from 'react';
import {
	AppRegistry,
	View,
	Button,
	Alert,
	Text,
} from 'react-native';

class reactTutApp extends Component {
	clickHandler() {
		fetch('http://anask.xyz/ledger/react-check', {
			method: 'POST',
			headers: {
				'Accept': 'application/json',
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({
				led: 'heyy',
				secondParam: 'yourOtherValue',
			})
		}).then((response) => response.json())
			.then((responseJson) => {
				this.setState({
					showText: JSON.stringify(responseJson)
				})
			})
			.catch((error) => {
				console.error(error);
			});
	}

	constructor() {
		super();
		this.state = { showText: null };

		this.clickHandler = this.clickHandler.bind(this);
	}
	render() {
		let check = this.state.showText ? this.state.showText : "yo";
		return (
			<View style={{ padding: 20 }}>
				<Button
					onPress={this.clickHandler}
					title="Click Me"
					color="#841584"
				/>
				<Text style={{ padding: 20 }}>{check}</Text>
			</View>
		);
	}
}

AppRegistry.registerComponent('reactTutApp', () => reactTutApp);
